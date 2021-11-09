#include <iostream>
#include <bitset>
#include "../../utilities/print-success.cpp"

uint32_t reverseBits(uint32_t n) {
  uint32_t result = 0;
  for (int i = 0; i < 32; ++i) {
    result <<= 1;
    result += n & 1;
    std::cout << std::bitset<32>(result) << "\n";
    n >>= 1;
  }
  return result;
}

int main() {
  printSuccess(reverseBits(0b00000010100101000001111010011100) == 0b00111001011110000010100101000000);
  printSuccess(reverseBits(0b11111111111111111111111111111101) == 0b10111111111111111111111111111111);

  return 0;
}
