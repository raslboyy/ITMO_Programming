#include "Station.hpp"
#include "Route.hpp"

void Station::add_route(const std::shared_ptr<Route> &route) {
  routes_.emplace_back(route);
}