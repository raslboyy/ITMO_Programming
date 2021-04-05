#include <iostream>
#include <string>
#include <set>
#include <memory>
#include <locale>
#include <unordered_map>

#include "libs/pugixml/src/pugixml.hpp"
#include "libs/pugixml/src/pugiconfig.hpp"
#include "libs/StringPro/src/StringPro.hpp"
#include "src/GeoPoint.hpp"
#include "src/Station.hpp"
#include "src/Street.hpp"

struct XmlStation {
  explicit XmlStation(const auto &i) :
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
  std::unordered_map<int, std::shared_ptr<Route>> route_map;
  std::unordered_map<String, std::shared_ptr<Street>> street_map;
  for (const auto &i : doc.child(L"dataset")) {
    XmlStation current(i);
    std::shared_ptr<Station> geo_object(new Station(
        current.name_stopping,
        current.the_official_name,
        std::stoi(current.number),
        std::stod(stringPro::split(current.coordinates, L",")[0]),
        std::stod(stringPro::split(current.coordinates, L",")[1])
        ));
    for (const auto &num : stringPro::split(current.number, L" .,")) {
      if (route_map.find(std::stoi(num)) != route_map.end())
        route_map[std::stoi(num)]->add_station(geo_object);
      else
        route_map[std::stoi(num)] =
    }


  }

//  std::shared_ptr<int> p = std::make_shared<int>(13);
//  {
//    A a(p, 10);
//    std::cout << p.use_count() << std::endl;
//  }
//  std::cout << p.use_count() << std::endl;
//  p.reset();
//  std::cout << p.use_count() << std::endl;
//  std::wcout << int(L'А') << ' ' << int(L'я') << ' ' << wchar_t(1104) << '\n';

  return 0;
}
