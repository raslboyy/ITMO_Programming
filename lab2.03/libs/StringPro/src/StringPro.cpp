#include "StringPro.hpp"

#include <string>

String stringPro::normalization(const String &str) {
  String copy = str;
  const static auto beginEnd = std::wregex(L"((^\\s+)|(\\s+$))");
  copy = std::regex_replace(copy, beginEnd, L"");
  const static auto body = std::wregex(L"(\\s+)");
  copy = std::regex_replace(copy, body, L" ");
  return copy;
}

String stringPro::toLower(const String &str) {
  String copy = str;
  std::transform(copy.begin(), copy.end(), copy.begin(),
                 [](wchar_t c){ return std::towlower(c); });
  return copy;
}

String stringPro::erase(const String &str, const String& pattern) {
  const auto r = std::wregex(L"([" + pattern + L"])");
  return std::regex_replace(str, r, L"");
}

String stringPro::erase_word(const String &str, const String &word) {
  String copy = str;
  const auto r = std::wregex(L"\\b" + word + L"\\b");
  copy = std::regex_replace(copy, r, L"");
  return copy;
}

std::vector<String> stringPro::split(const String &s, const String& pattern) {
  const auto r = std::wregex(L"([" + pattern + L"])");
  return std::vector<String>{
      std::wsregex_token_iterator(s.begin(), s.end(), r, -1),
      std::wsregex_token_iterator()
  };
}