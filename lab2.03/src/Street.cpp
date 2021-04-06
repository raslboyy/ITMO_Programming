#include "Street.hpp"

std::vector<String> unificationGarbage = {
    L"проспект",
    L"пр-т",
    L"пр-д",
    L"пр.",
    L"пр",
    L"улица",
    L"ул.",
    L"ул",
    L"шоссе",
    L"ш.",
    L"ш",
    L"площадь",
    L"пл.",
    L"пл",
    L"переулок",
    L"пер",
    L"пер.",
    L"набережная",
    L"наб",
    L"наб.",
    L"мост",
    L"проезд",
    L"дорога",
    L"дор",
    L"бульвар",
    L"бул",
    L"б.",
    L"б",
    L"аллея",
    L"коса",
    L"линия",
    L"спуск",
    L"канал",
};

// удаление русских символов не выделсть в отдельную функцию потому что слишком узкая направленность ?
Street::Street(const String &name) :
    name_(stringPro::normalization(name)),
    objects_() {
  String s = stringPro::toLower(stringPro::normalization(name));
  for (const auto &i : unificationGarbage)
    s = stringPro::erase_word(s, i);
  for (const auto &i : s)
    if ((L'а' <= i && i <= L'я') || i == L'ё' || ('0' <= i && i <= '9'))
      uniform_name_.push_back(i);

};

void Street::add_obj(const std::shared_ptr<GeoObject> &obj) {
  objects_.emplace_back(obj);
}
