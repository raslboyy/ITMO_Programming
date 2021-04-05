#ifndef LAB2_04__MYALGORITHM_HPP_
#define LAB2_04__MYALGORITHM_HPP_

// Названия? с _ и caps
// Строка 50 ?

namespace myAlgorithm {

template<class T>
class equality {
 public:
  explicit equality(const T &value) : value_(value) {};
  bool operator()(T other) {
    return other == value_;
  };
 private:
  T value_;
};

template<class UnaryPredicate>
class negation {
 public:
  explicit negation(const UnaryPredicate &p) : p_(p) {};
  template<class T>
  bool operator()(const T &value) {
    return !p_(value);
  };
 private:
  UnaryPredicate &p_;
};

template<class InputIt>
InputIt next(InputIt it) {
  return ++it;
}
template<class InputIt>
InputIt prev(InputIt it) {
  return --it;
}

template<class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p) {
  for (; first != last; ++first)
    if (p(*first))
      return first;
  return last;
}

template<class InputIt, class UnaryPredicate>
InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate p) {
  return myAlgorithm::find_if(first, last, negation(p));
}

template<class InputIt, class UnaryPredicate>
InputIt find_if_end(InputIt first, InputIt last, UnaryPredicate p) {
  auto i = last;
  if (first != last) {
    for (--last; last != first; --last)
      if (p(*last))
        return last;
    if (p(*first))
      return first;
  }
  return i;
}

template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
  return (myAlgorithm::find_if_not(first, last, p) == last);
}

template<class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
  return myAlgorithm::find_if(first, last, p) != last;
}

template<class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
  return myAlgorithm::find_if(first, last, p) == last;
}

template<class InputIt, class UnaryPredicate>
bool one_of(InputIt first, InputIt last, UnaryPredicate p) {
  auto it = myAlgorithm::find_if(first, last, p);
  if (it == last)
    return false;
  return myAlgorithm::find_if(++it, last, p) == last;
}

template<class InputIt, class UnaryPredicate>
bool is_partitioned(InputIt first, InputIt last, UnaryPredicate p) {
  return myAlgorithm::none_of(myAlgorithm::find_if_not(first, last, p), last, p);
}

template<class InputIt, class Compare>
InputIt is_sorted_until(InputIt first, InputIt last, Compare comp) {
  if (first != last) {
    InputIt next = first;
    for (++next; next != last; first = next++)
      if (!comp(*first, *next))
        return next;
  }
  return last;
}

template<class InputIt, class Compare>
bool is_sorted(InputIt first, InputIt last, Compare comp) {
  return myAlgorithm::is_sorted_until(first, last, comp) == last;
}

template<class InputIt, class T>
InputIt find_not(InputIt first, InputIt last, T value) {
  return myAlgorithm::find_if_not(first, last, equality<T>(value));
}

template<class InputIt, class T>
InputIt find_backward(InputIt first, InputIt last, T value) {
  return myAlgorithm::find_if_end(first, last, equality<T>(value));
}

template<class InputIt, class UnaryPredicate>
bool is_palindrome(InputIt first, InputIt last, UnaryPredicate p) {
  if (first != last) {
    --last;
    if (first != last)
      do {
        if (p(*first) != p(*last))
          return false;
        ++first;
        --last;
      } while (last != myAlgorithm::prev(first) && last != first);
  }
  return true;
}
}

#endif //LAB2_04__MYALGORITHM_HPP_
