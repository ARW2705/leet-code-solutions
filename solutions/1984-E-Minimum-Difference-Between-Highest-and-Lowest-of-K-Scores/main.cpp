#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "../../utilities/print-success.cpp"

int minimumDifference(std::vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  int minDiff = std::numeric_limits<int>::max();
  for (int i = 0; (i + k - 1) < nums.size(); ++i) {
    int diff = nums[i + k - 1] - nums[i];
    if (diff < minDiff) {
      minDiff = diff;
    }
  }
  return minDiff;
}

int main() {
  std::vector<int> v1 { 90 };
  printSuccess(minimumDifference(v1, 1) == 0);

  std::vector<int> v2 { 9, 4, 1, 7 };
  printSuccess(minimumDifference(v2, 2) == 2);

  return 0;
}
