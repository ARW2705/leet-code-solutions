#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"

std::vector<int> buildArray(std::vector<int>& nums) {
  int size = nums.size();
  std::vector<int> result(size);
  for (int i = 0; i < size; ++i) {
    result[i] = nums[nums[i]];
  }
  return result;
}

int main() {
  std::vector<int> v1 { 0, 2, 1, 5, 3, 4 };
  std::vector<int> e1 { 0, 1, 2, 4, 5, 3 };
  std::vector<int> r1 = buildArray(v1);
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 { 0, 2, 1, 5, 3, 4 };
  std::vector<int> e2 { 0, 1, 2, 4, 5, 3 };
  std::vector<int> r2 = buildArray(v2);
  printSuccess(compareVector(e2, r2));

  return 0;
}
