#ifndef LAB2_03_SRC_TROLLROUTE_HPP_
#define LAB2_03_SRC_TROLLROUTE_HPP_

#include "Route.hpp"

#include <utility>

class TrollRoute : public Route {
 public:
  explicit TrollRoute(String number) : Route(std::move(number)) {};
};

#endif //LAB2_03_SRC_TROLLROUTE_HPP_
