#include <iostream>
#include <fstream>
#include "Cube/Field.h"
#include "Cube/Cube.h"
#include "genetic_algorithm/genetic_algorithm.h"

using namespace std;

int main() {

  ifstream fin("input.txt");
  int n;
  fin >> n;
  Cube a(n);
  fin >> a;

  cout << a;

  return 0;
}
