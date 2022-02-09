#include <iostream>
#include <vector>
#include "num-array.hpp"
#include "../../utilities/print-success.cpp"

int main() {
  std::vector<int> nums { -2, 0, 3, -5, 2, -1 };
  NumArray* numArray = new NumArray(nums);
  printSuccess(numArray->sumRange(0, 2) == 1);
  printSuccess(numArray->sumRange(2, 5) == -1);
  printSuccess(numArray->sumRange(0, 5) == -3);

  return 0;
}
