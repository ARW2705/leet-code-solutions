#include <iostream>
#include "../../utilities/print-success.cpp"

int sumBase(int n, int k) {
  int maxDigit = 1;
  while (maxDigit <= n / k) {
    maxDigit *= k;
  }

  int sum = 0;
  while (n > 0) {
    int times = n / maxDigit;
    sum += times;
    n -= maxDigit * times;
    maxDigit /= k;
  }

  return sum;
}

int main() {
  printSuccess(sumBase(34, 6) == 9);
  printSuccess(sumBase(10, 10) == 1);
  printSuccess(sumBase(42, 2) == 3);

  return 0;
}
