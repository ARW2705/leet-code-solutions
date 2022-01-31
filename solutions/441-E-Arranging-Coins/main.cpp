#include <iostream>
#include <cmath>
#include "../../utilities/print-success.cpp"

int arrangeCoins(int n) {
  long long total = 1;
  long long step = 1;
  while (total < n) {
    ++step;
    total += step;
  }
  return static_cast<int>(total == static_cast<long long>(n) ? step : step - 1);
}

int main() {
  printSuccess(arrangeCoins(5) == 2);
  printSuccess(arrangeCoins(8) == 3);
  printSuccess(arrangeCoins(1) == 1);
  printSuccess(arrangeCoins(3) == 2);
  printSuccess(arrangeCoins(10) == 4);
  return 0;
}
