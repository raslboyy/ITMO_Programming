#include <iostream>
#include <memory>
#include <string>
#include <set>
#include <memory>
#include <locale>
#include <unordered_map>
#include <map>

#include "libs/pugixml/src/pugixml.hpp"
#include "libs/pugixml/src/pugiconfig.hpp"
#include "libs/StringPro/src/StringPro.hpp"
#include "src/GeoPoint.hpp"
#include "src/TramRoute.hpp"
#include "src/TrollRoute.hpp"
#include "src/BusRoute.hpp"
#include "src/Station.hpp"
#include "src/Street.hpp"

const double EPS = 1e-7;

struct XmlStation {
  explicit XmlStation(const pugi::xml_node &i) :
      number(i.child(L"number").child_value()),
      type_of_vehicle(i.child(L"type_of_vehicle").child_value()),
      object_type(i.child(L"object_type").child_value()),
      name_stopping(i.child(L"name_stopping").child_value()),
      the_official_name(i.child(L"the_official_name").child_value()),
      location(i.child(L"location").child_value()),
      routes(i.child(L"routes").child_value()),
      coordinates(i.child(L"coordinates").child_value()) {}
  String number;
  String type_of_vehicle;
  String object_type;
  String name_stopping;
  String the_official_name;
  String location;
  String routes;
  String coordinates;
};

int main() {

  setlocale(LC_ALL, "rus");

  pugi::xml_document doc;
  doc.load_file("data.xml");
  auto body = doc.child(L"dataset");
  std::map<String, std::shared_ptr<Route>> route_map;
  std::map<String, std::shared_ptr<Street>> street_map;
  for (const auto &i : doc.child(L"dataset")) {
    XmlStation current(i);
    std::shared_ptr<Station> geo_object(new Station(
        current.name_stopping,
        current.the_official_name,
        std::stoi(current.number),
        std::stod(stringPro::split(stringPro::erase(current.coordinates, L"."), L",")[0]) / 1e6,
        std::stod(stringPro::split(stringPro::erase(current.coordinates, L"."), L",")[1]) / 1e6
        ));
    for (const auto &num : stringPro::split(current.routes, L" .,")) {
      if (route_map.find(num) == route_map.end()) {
        if (current.type_of_vehicle == L"Троллейбус")
          route_map[num] = std::make_shared<TrollRoute>(num);
        else if (current.type_of_vehicle == L"Трамвай")
          route_map[num] = std::make_shared<TramRoute>(num);
        else if (current.type_of_vehicle == L"Автобус")
          route_map[num] = std::make_shared<BusRoute>(num);
      }
      route_map[num]->add_station(geo_object);
      geo_object->add_route(route_map[num]);
    }
    for (const auto &st : stringPro::split(current.location, L",")) {
      Street street(st);
      if (street.uniform_name().empty())
        continue;
      if (street_map.find(street.uniform_name()) == street_map.end())
        street_map[street.uniform_name()] = std::make_shared<Street>(st);
      street_map[street.uniform_name()]->add_obj(geo_object);
    }
  }

  int max_route_by_station[3] = {};
  double max_route_by_coordinates[3] = {};
  for (const auto &route : route_map) {
    if (dynamic_cast<TrollRoute *>(route.second.get())) {
      max_route_by_station[0] = std::max(max_route_by_station[0], route.second->count_station());
      max_route_by_coordinates[0] = std::max(max_route_by_coordinates[0], route.second->len());
    }
    else if (dynamic_cast<TramRoute *>(route.second.get())) {
      max_route_by_station[1] = std::max(max_route_by_station[1], route.second->count_station());
      max_route_by_coordinates[1] = std::max(max_route_by_coordinates[1], route.second->len());
    }
    else {
      max_route_by_station[2] = std::max(max_route_by_station[2], route.second->count_station());
      max_route_by_coordinates[2] = std::max(max_route_by_coordinates[2], route.second->len());
    }
  }


  std::wcout << L"Троллейбус - ";
  for (const auto &route : route_map)
    if (dynamic_cast<TrollRoute *>(route.second.get())) {
      if (route.second->count_station() == max_route_by_station[0]) {
        std::wcout << route.second->number() << L"(" << route.second->count_station() << L" станций) ";
        max_route_by_station[0] = -1;
      }
      if (fabs(route.second->len() - max_route_by_coordinates[0]) < EPS) {
        std::wcout << route.second->number() << L"(" << route.second->len() << L" км) ";
        max_route_by_coordinates[0] = -1;
      }
    }
  std::wcout << L"\n";


  std::wcout << L"Трамвай - ";
  for (const auto &route : route_map)
    if (dynamic_cast<TramRoute *>(route.second.get())) {
      if (route.second->count_station() == max_route_by_station[1]) {
        std::wcout << route.second->number() << L"(" << route.second->count_station() << L" станций) ";
        max_route_by_station[1] = -1;
      }
      if (fabs(route.second->len() - max_route_by_coordinates[1]) < EPS) {
        std::wcout << route.second->number() << L"(" << route.second->len() << L" км) ";
        max_route_by_coordinates[1] = -1;
      }
    }
  std::wcout << L"\n";


  std::wcout << L"Автобус - ";
  for (const auto &route : route_map)
    if (dynamic_cast<BusRoute *>(route.second.get())) {
      if (route.second->count_station() == max_route_by_station[2]) {
        std::wcout << route.second->number() << L"(" << route.second->count_station() << L" станций) ";
        max_route_by_station[2] = -1;
      }
      if (fabs(route.second->len() - max_route_by_coordinates[2]) < EPS) {
        std::wcout << route.second->number() << L"(" << route.second->len() << L" км) ";
        max_route_by_coordinates[2] = -1;
      }
    }
  std::wcout << L"\n";

  int max_street_by_station = 0;
  for (const auto &street : street_map)
    max_street_by_station = std::max(max_street_by_station, street.second->count_obj());

  for (const auto &street : street_map)
    if (street.second->count_obj() == max_street_by_station) {
      std::wcout << street.second->name() << L" " << street.second->count_obj() << L" станция" << std::endl;
      break;
    }

  return 0;
}
