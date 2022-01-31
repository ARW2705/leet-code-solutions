#include <iostream>
#include <limits>
#include <cmath>
#include "../../utilities/print-success.cpp"

// int findComplement(int num) {
//   int result = num;
//   int digit, mask;
//   int size = sizeof(int) * 8 - 1;
//   bool hasStarted = false;
//   for (int i = size; i >= 0; --i) {
//     digit = (num >> i & 1);
//     if (digit == 1) {
//       hasStarted = true;
//     }
//     if (hasStarted) {
//       mask = 1 << i;
//       if (digit) {
//         result &= ~mask;
//       } else {
//         result |= mask;
//       }
//     }
//   }
//   return result;
// }

int findComplement(int num) {
  int places = std::floor(std::log2(num)) + 1;
  unsigned int mask = (1 << places) - 1;
  return num ^ mask;
}

int main() {
  printSuccess(findComplement(5) == 2);
  printSuccess(findComplement(1) == 0);
  printSuccess(findComplement(std::numeric_limits<int>::max()) == 0);
  printSuccess(findComplement(2147483647) == 0);
  return 0;
}
