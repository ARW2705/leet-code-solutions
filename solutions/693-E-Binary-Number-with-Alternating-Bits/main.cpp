#include <iostream>
#include "../../utilities/print-success.cpp"

bool hasAlternatingBits(int n) {
  int previous;
  do {
    previous = n % 2;
    n /= 2;
    if (previous == n % 2) return false;
  } while (n);
  return true;
}

int main() {
  printSuccess(hasAlternatingBits(5));
  printSuccess(!hasAlternatingBits(7));
  printSuccess(!hasAlternatingBits(11));

  return 0;
}
