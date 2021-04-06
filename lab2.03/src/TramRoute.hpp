#ifndef LAB2_03_SRC_TRAMROUTE_HPP_
#define LAB2_03_SRC_TRAMROUTE_HPP_

#include "Route.hpp"

#include <utility>

class TramRoute : public Route {
 public:
  explicit TramRoute(String number) : Route(std::move(number)) {};
};

#endif //LAB2_03_SRC_TRAMROUTE_HPP_
