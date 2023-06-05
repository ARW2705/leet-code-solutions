#include <iostream>
#include "../../utilities/print-success.cpp"

using namespace std;

int minOperations(int n) {
  int operations = 0;
  for (int i = 0; i < n / 2; ++i) {
    operations += n - (2 * i) - 1;
  }
  return operations;
}

int main() {
  int r1 = minOperations(3);
  cout << r1 << "\n";
  printSuccess(r1 == 2);

  int r2 = minOperations(6);
  cout << r2 << "\n";
  printSuccess(r2 == 9);

  int r3 = minOperations(9);
  cout << r3 << "\n";
  printSuccess(r3 == 20);
}
