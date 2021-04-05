#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include "MyAlgorithm.hpp"

struct CPoint {

  double x;
  double y;
};

int main() {

  auto is_even = [](int i) { return i % 2 == 0; };
  auto is_positive = [](int i) { return i > 0; };
  auto comp = [](CPoint a, CPoint b) {
    if (a.x != b.x)
      return a.x < b.x;
    return a.y < b.y;
  };
  std::vector<int> v_int = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<int> s_int = {1, 1, 1, 2, 1};
  std::list<int> l_int = {1, 1, 1, -1, -1};

  std::cout << "all_of: ";
  std::cout << myAlgorithm::all_of(v_int.begin(), v_int.end(), is_positive) << ' ';
  std::cout << myAlgorithm::all_of(l_int.begin(), l_int.end(), is_positive) << std::endl;

  std::cout << "any_of: ";
  std::cout << myAlgorithm::any_of(v_int.begin(), v_int.end(), is_even) << ' ';
  std::cout << myAlgorithm::any_of(l_int.begin(), l_int.end(), is_even) << std::endl;

  std::cout << "none_of: ";
  std::cout << myAlgorithm::none_of(v_int.begin(), v_int.end(), is_even) << ' ';
  std::cout << myAlgorithm::none_of(l_int.begin(), l_int.end(), is_even) << std::endl;

  std::cout << "one_of: ";
  std::cout << myAlgorithm::one_of(v_int.begin(), v_int.end(), is_even) << ' ';
  std::cout << myAlgorithm::one_of(l_int.begin(), l_int.end(), is_even) << ' ';
  std::cout << myAlgorithm::one_of(s_int.begin(), s_int.end(), is_even) << std::endl;

  std::vector<CPoint> v_point = {{1, 1}, {2, 2}, {3, 2}, {3, 3}};
  std::list<CPoint> l_point = {{2, 2}, {1, 1}};
  std::cout << "is_sorted: ";
  std::cout << myAlgorithm::is_sorted(v_point.begin(), v_point.end(), comp) << ' ';
  std::cout << myAlgorithm::is_sorted(l_point.begin(), l_point.end(), comp) << std::endl;

  std::cout << "is_partitioned: ";
  auto p = [](CPoint i) { return i.x == i.y; };
  std::cout << myAlgorithm::is_partitioned(v_point.begin(), v_point.end(), p) << ' ';
  v_point[3] = {1, 2};
  std::cout << myAlgorithm::is_partitioned(v_point.begin(), v_point.end(), p) << std::endl;

  std::cout << "find_not: ";
  std::cout << *myAlgorithm::find_not(l_int.begin(), l_int.end(), 1) << std::endl;

  std::cout << "find_backward: index = ";
  std::cout << myAlgorithm::find_backward(v_int.begin(), v_int.end(), 7) - v_int.begin() << std::endl;

  v_int = {1, 2, 2, 4, 6, 3};
  l_int = {2, 2, 2, 1};
  std::cout << "is_palindrome: ";
  std::cout << myAlgorithm::is_palindrome(v_int.begin(), v_int.end(), is_even) << ' ';
  std::cout << myAlgorithm::is_palindrome(l_int.begin(), l_int.end(), is_even) << std::endl;

  return 0;
}
