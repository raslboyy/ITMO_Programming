#ifndef LAB2_03_SRC_BUSROUTE_HPP_
#define LAB2_03_SRC_BUSROUTE_HPP_

#include "Route.hpp"

#include <utility>

class BusRoute : public Route {
 public:
  explicit BusRoute(String number) : Route(std::move(number)) {};
};

#endif //LAB2_03_SRC_BUSROUTE_HPP_
