#include <iostream>
#include "../../utilities/print-success.cpp"

int smallestEvenMultiple(int n) {
  return n % 2 == 0 ? n : n * 2;
}

int main() {
  printSuccess(smallestEvenMultiple(5) == 10);
  printSuccess(smallestEvenMultiple(6) == 6);

  return 0;
}
