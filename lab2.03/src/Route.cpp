#include "Route.hpp"

void Route::add_station(Station *station) {
  is_ = true;
  stations_.emplace_back(station);
}
double Route::len() {
  if (!is_)
    return len_;
  is_ = false;
  const double INF = 1e9;
  int n = stations_.size();
  double sum = 0;
  std::vector<bool> used(n);
  std::vector<double> min_e(n, INF);
  min_e[0] = 0;
  for (int i = 0; i < n; ++i) {
    int v = -1;
    for (int j = 0; j < n; ++j)
      if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
        v = j;

    used[v] = true;
    sum += min_e[v];
    for (int to = 0; to < n; ++to) {
      double len = GeoObject::len(*stations_[to].get(), *stations_[v].get());
      if (len < min_e[to])
        min_e[to] = len;
    }
  }
  return sum;
}

