#include <iostream>
#include <limits>
#include <bitset>
#include "../../utilities/print-success.cpp"

bool isPowerOfTwo(int n) {
  if (n < 1) {
    return false;
  }
  bool found = false;
  int intSize = (sizeof(int) * 8);
  for (int i = 0; i < intSize; ++i) {
    if (((n >> i) & 1) == 1) {
      if (found && i < intSize) {
        return false;
      }
      found = true;
    }
  }
  return found;
}

int main() {
  printSuccess(isPowerOfTwo(1));
  printSuccess(isPowerOfTwo(16));
  printSuccess(!isPowerOfTwo(3));
  printSuccess(isPowerOfTwo(4));
  printSuccess(!isPowerOfTwo(5));
  printSuccess(!isPowerOfTwo(-2147483646));
  printSuccess(!isPowerOfTwo(-2147483648));
  return 0;
}
