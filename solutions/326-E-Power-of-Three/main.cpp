#include <iostream>
#include <limits>
#include "../../utilities/print-success.cpp"

bool isPowerOfThree(int n) {
  if (n < 0) return false;
  long long product = 1;
  while (true) {
    if (product > std::numeric_limits<int>::max() || product > n) return false;
    if (product == n) return true;
    product *= 3;
  }
}

int main() {
  printSuccess(isPowerOfThree(27));
  printSuccess(!isPowerOfThree(0));
  printSuccess(isPowerOfThree(9));
  printSuccess(!isPowerOfThree(45));
  printSuccess(isPowerOfThree(1));

  return 0;
}
