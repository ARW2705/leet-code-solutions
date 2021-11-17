#include <iostream>
#include <cmath>
#include <set>
#include "../../utilities/print-success.cpp"

int getSumOfSquares(int n) {
  int mod;
  int sum = 0;
  while (n > 0) {
    mod = n % 10;
    sum += std::pow(mod, 2);
    n /= 10;
  }
  return sum;
}

bool isHappy(int n) {
  std::set<int> landmarks;
  int sumOfSquares = n;
  do {
    sumOfSquares = getSumOfSquares(sumOfSquares);
    if (landmarks.find(sumOfSquares) != landmarks.end()) {
      return false;
    } else {
      landmarks.insert(sumOfSquares);
    }
  } while (sumOfSquares != 1);
  return true;
}

int main() {
  printSuccess(isHappy(19));
  printSuccess(!isHappy(2));
  return 0;
}
