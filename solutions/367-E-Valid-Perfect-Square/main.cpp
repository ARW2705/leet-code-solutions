#include <iostream>
#include "../../utilities/print-success.cpp"

bool isPerfectSquare(int num) {
  long long longNum = num, base = 0, square;
  do {
    ++base;
    square = base * base;
  } while (square < longNum);
  return square == longNum;
}

int main() {
  printSuccess(isPerfectSquare(1));
  printSuccess(isPerfectSquare(16));
  printSuccess(!isPerfectSquare(14));
  printSuccess(!isPerfectSquare(2147483647));

  return 0;
}
