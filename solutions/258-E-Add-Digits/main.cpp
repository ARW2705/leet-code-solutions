#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

int addDigits(int num) {
  int sum = num;
  int currentSum = 0, currentNum, mod;
  while (sum > 9) {
    currentNum = sum;
    while (currentNum > 0) {
      mod = currentNum % 10;
      currentSum += mod;
      currentNum /= 10;
    }
    sum = currentSum;
    currentSum = 0;
  }
  return sum;
}

int main() {
  printSuccess(addDigits(38) == 2);
  printSuccess(addDigits(0) == 0);
  printSuccess(addDigits(10) == 1);
  return 0;
}
