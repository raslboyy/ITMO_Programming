#ifndef LAB2_03_SRC_ROUTE_HPP_
#define LAB2_03_SRC_ROUTE_HPP_

#include <utility>
#include <vector>
#include <memory>

#include "../libs/StringPro/src/StringPro.hpp"

// функция len const изменить поле is_
// const указатель ?

class Station;

class Route {
 public:
  explicit Route(String number) :
      number_(std::move(number)),
      stations_(),
      is_(false),
      len_(0) {}
  void add_station(const std::shared_ptr<Station> &station);

  [[nodiscard]] String number() const { return number_; }
  [[nodiscard]] int count_station() const { return stations_.size(); }
  [[nodiscard]] double len();

  Route &operator=(const Route &other) = delete;
  Route(const Route &other) = delete;

  virtual ~Route() = default;
 private:
  String number_;
  double len_;
  bool is_;
  std::vector<std::shared_ptr<Station>> stations_;
};

#endif //LAB2_03_SRC_ROUTE_HPP_
