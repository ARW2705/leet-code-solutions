#include <iostream>
#include <vector>
#include <algorithm>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"
#include "../../utilities/print-vector.cpp"

std::vector<int> targetIndices(std::vector<int>& nums, int target) {
  std::sort(nums.begin(), nums.end());
  int size = nums.size();
  std::vector<int> result;
  for (int i = 0; i < size; ++i) {
    if (nums[i] == target) {
      result.push_back(i);
    }
  }
  return result;
}

int main() {
  std::vector<int> v1 { 1, 2, 5, 2, 3 };
  std::vector<int> r1 = targetIndices(v1, 2);
  std::vector<int> e1 { 1, 2 };
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 { 1, 2, 5, 2, 3 };
  std::vector<int> r2 = targetIndices(v2, 3);
  std::vector<int> e2 { 3 };
  printSuccess(compareVector(e2, r2));

  std::vector<int> v3 { 1, 2, 5, 2, 3 };
  std::vector<int> r3 = targetIndices(v3, 5);
  std::vector<int> e3 { 4 };
  printSuccess(compareVector(e3, r3));

  std::vector<int> v4 { 1, 2, 5, 2, 3 };
  std::vector<int> r4 = targetIndices(v4, 4);
  std::vector<int> e4 {};
  printSuccess(compareVector(e4, r4));

  std::vector<int> v5 { 2, 1 };
  std::vector<int> r5 = targetIndices(v5, 1);
  std::vector<int> e5 { 0 };
  printSuccess(compareVector(e5, r5));

  return 0;
}
