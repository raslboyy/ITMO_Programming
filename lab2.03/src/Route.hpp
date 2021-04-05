#ifndef LAB2_03_SRC_ROUTE_HPP_
#define LAB2_03_SRC_ROUTE_HPP_

#include <vector>
#include <memory>

#include "Station.hpp"

// функция len const изменить поле is_
// const указатель ?

class Route {
 public:
  Route(int number) :
      number_(number),
      stations_(),
      is_(false),
      len_(0) {}
  void add_station(Station* station);

  [[nodiscard]] int count_station() const { return stations_.size(); }
  [[nodiscard]] double len();

  Route &operator=(const Route &other) = delete;
  Route(const Route &other) = delete;

  virtual ~Route() = default;
 private:
  int number_;
  int len_;
  bool is_;
  std::vector<std::shared_ptr<Station>> stations_;
};

#endif //LAB2_03_SRC_ROUTE_HPP_
