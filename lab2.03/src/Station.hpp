#ifndef LAB2_03_SRC_STATION_HPP_
#define LAB2_03_SRC_STATION_HPP_

#include <utility>
#include <memory>

#include "../libs/StringPro/src/StringPro.hpp"

#include "GeoObject.hpp"

// почему рекомендует заменить const String &name на std::move ?
// дефолтные конструктор копирования норм ?

class Route;

class Station : public GeoObject {
 public:
  Station(String name, String officialName, int number, double x, double y) :
      GeoObject(x, y),
      name_(std::move(name)),
      official_name_(std::move(officialName)),
      number_(number) {};
  void add_route(const std::shared_ptr<Route> &route);


 private:
  String name_;
  String official_name_;
  int number_;
  std::vector<std::shared_ptr<Route>> routes_;
};

#endif //LAB2_03_SRC_STATION_HPP_