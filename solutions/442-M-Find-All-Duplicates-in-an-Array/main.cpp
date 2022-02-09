#include <iostream>
#include <vector>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

std::vector<int> findDuplicates(std::vector<int>& nums) {
  std::vector<int> result;
  int size = nums.size();
  int absVal, index;

  for (int i = 0; i < size; ++i) {
    absVal = std::abs(nums[i]);
    index = absVal - 1;
    if (nums[index] < 0) {
      result.push_back(absVal);
    } else {
      nums[index] *= -1;
    }
  }

  return result;
}

int main() {
  std::vector<int> v1 { 4,3,2,7,8,2,3,1 };
  std::vector<int> e1 { 2, 3 };
  std::vector<int> r1 = findDuplicates(v1);
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 { 1, 1, 2 };
  std::vector<int> e2 { 1 };
  std::vector<int> r2 = findDuplicates(v2);
  printSuccess(compareVector(e2, r2));

  std::vector<int> v3 { 1 };
  std::vector<int> e3 { };
  std::vector<int> r3 = findDuplicates(v3);
  printSuccess(compareVector(e3, r3));

  return 0;
}
