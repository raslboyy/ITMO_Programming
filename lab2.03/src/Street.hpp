#ifndef LAB2_03_SRC_STREET_HPP_
#define LAB2_03_SRC_STREET_HPP_

#include <utility>
#include <vector>
#include <memory>

#include "GeoObject.hpp"
#include "../libs/StringPro/src/StringPro.hpp"

// static inline ?
// включение библиотек ?

class Street {
 public:
  explicit Street(const String &name);

  [[nodiscard]] String name() const { return name_; }
  [[nodiscard]] String uniform_name() const { return uniform_name_; }

  void add_obj(const std::shared_ptr<GeoObject> &obj);
  [[nodiscard]] int count_obj() const { return objects_.size(); }

  Street(const Street &other) = delete;
  Street &operator=(const Street &other) = delete;
 private:
  String name_;
  String uniform_name_;
  std::vector<std::shared_ptr<GeoObject>> objects_;

  //  static inline const std::vector<String> unificationGarbage = {
  //      L"проспект",
  //  };
};

#endif //LAB2_03_SRC_STREET_HPP_
