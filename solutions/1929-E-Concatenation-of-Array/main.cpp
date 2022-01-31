#include <iostream>
#include <vector>
#include "../../utilities/print-vector.cpp"

std::vector<int> getConcatenation(std::vector<int>& nums) {
  int size = nums.size();
  std::vector<int> concat(size * 2);
  for (int i = 0; i < size; ++i) {
    concat[i] = nums[i];
    concat[i + size] = nums[i];
  }
  return concat;
}

int main() {
  std::vector<int> v1 { 1, 2, 1 };
  std::vector<int> r1 = getConcatenation(v1);
  printVector(r1);

  std::vector<int> v2 { 1, 3, 2, 1 };
  std::vector<int> r2 = getConcatenation(v2);
  printVector(r2);
  return 0;
}
