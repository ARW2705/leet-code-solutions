#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-vector.cpp"

std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
  std::vector<int> counts(101, 0);
  int currentMax = 0;
  for (int num : nums) {
    ++counts[num];
    currentMax = std::max(currentMax, num);
  }

  int currentCount = 0;
  int tmp;
  for (int i = 0; i < currentMax + 1; ++i) {
    if (counts[i]) {
      tmp = currentCount;
      currentCount += counts[i];
      counts[i] = tmp;
    }
  }

  for (int i = 0; i < nums.size(); ++i) {
    nums[i] = counts[nums[i]];
  }

  return nums;
}

int main() {
  std::vector<int> v1 { 8, 1, 2, 2, 3 };
  std::vector<int> e1 { 4, 0, 1, 1, 3 };
  std::vector<int> r1 = smallerNumbersThanCurrent(v1);
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 { 6, 5, 4, 8 };
  std::vector<int> e2 { 2, 1, 0, 3 };
  std::vector<int> r2 = smallerNumbersThanCurrent(v2);
  printSuccess(compareVector(e2, r2));

  std::vector<int> v3 { 7, 7, 7, 7 };
  std::vector<int> e3 { 0, 0, 0, 0 };
  std::vector<int> r3 = smallerNumbersThanCurrent(v3);
  printSuccess(compareVector(e3, r3));

  return 0;
}
