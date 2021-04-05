#ifndef LAB2_03_LIBS_STRINGPRO_SRC_STRINGPRO_HPP_
#define LAB2_03_LIBS_STRINGPRO_SRC_STRINGPRO_HPP_

#include <string>
#include <vector>
#include <regex>
#include <algorithm>

typedef std::wstring String;

namespace stringPro {
  String normalization(const String &str); // удаление "лишних" пробелов
  String toLower(const String &str);
  String erase(const String &str, const String& pattern);
  String erase_word(const String &str, const String &word);
  std::vector<String> split(const String& s, const String& pattern);
}

#endif //LAB2_03_LIBS_STRINGPRO_SRC_STRINGPRO_HPP_
