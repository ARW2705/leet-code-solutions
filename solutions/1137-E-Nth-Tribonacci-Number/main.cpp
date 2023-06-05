#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

std::vector<int> previous(38, -1);

int tribonacci(int n) {
  if (n == 0) return 0;
  if (n < 3) return 1;
  if (previous[n] != -1) return previous[n];

  int result = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
  previous[n] = result;
  return result;
}

int main() {
  printSuccess(tribonacci(4) == 4);
  printSuccess(tribonacci(25) == 1389537);

  return 0;
}
