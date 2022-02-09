#include <iostream>
#include "../../utilities/print-success.cpp"

int climbStairs(int n) {
  int previousCount = 1;
  int wayCount = 1;
  int tmp;
  for (int i = 1; i < n; ++i) {
    tmp = wayCount;
    wayCount += previousCount;
    previousCount = tmp;
  }
  return wayCount;
}

int main() {
  printSuccess(climbStairs(2) == 2);
  printSuccess(climbStairs(3) == 3);
  printSuccess(climbStairs(5) == 8);
  return 0;
}
