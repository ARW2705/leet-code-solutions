#include <iostream>
#include "../../utilities/print-success.cpp"

int xorOperation(int n, int start) {
  int size = n * 2 + start;
  int result = start;
  for (int i = start + 2; i < size; i += 2) {
    result ^= i;
  }
  std::cout << result << "\n";
  return result;
}

int main() {
  printSuccess(xorOperation(5, 0) == 8);
  printSuccess(xorOperation(4, 3) == 8);

  return 0;
}
