#include <iostream>
#include "../../utilities/print-success.cpp"

int hammingWeight(uint32_t n) {
  int oneCount = 0;
  for (int i = 0; i < 32; ++i) {
    oneCount += n & 1;
    n >>= 1;
  }
  return oneCount;
}

int main() {
  printSuccess(hammingWeight(0b00000000000000000000000000001011) == 3);
  printSuccess(hammingWeight(0b00000000000000000000000010000000) == 1);
  printSuccess(hammingWeight(0b11111111111111111111111111111101) == 31);
  return 0;
}
