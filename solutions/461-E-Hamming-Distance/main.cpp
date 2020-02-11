#include <iostream>

void printResult(int x, int y, int expected, int result) {
  std::cout
    << "For x = "
    << x
    << ", y = "
    << y
    << "; Hamming Distance is "
    << result
    << ";\n"
    << (expected == result ? "PASS": "FAIL")
    << "\n";
}

int hammingDistanceWithMods(int x, int y) {
  int total = 0;
  while (x > 0 || y > 0) {
    total += (x % 2) != (y % 2);
    x /= 2;
    y /= 2;
  }
  return total;
}

int hammingDistanceWithBitwise(int x, int y) {
  int total = 0;
  for (int places = 0; places < (sizeof(int) * 8); ++places) {
    total += ((x >> places) & 1) != ((y >> places) & 1);
  }
  return total;
}

int main() {
  int hammingDistance1a = hammingDistanceWithMods(1, 4);
  int hammingDistance1b = hammingDistanceWithBitwise(1, 4);
  printResult(1, 4, 2, hammingDistance1a);
  printResult(1, 4, 2, hammingDistance1b);

  int hammingDistance2a = hammingDistanceWithMods(15, 80);
  int hammingDistance2b = hammingDistanceWithBitwise(15, 80);
  printResult(15, 80, 6, hammingDistance2a);
  printResult(15, 80, 6, hammingDistance2b);
  return 0;
}
