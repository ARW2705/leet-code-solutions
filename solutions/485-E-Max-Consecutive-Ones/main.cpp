#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

int findMaxConsecutiveOnes(std::vector<int>& nums) {
  int maxCount = 0, currentCount = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] == 1) {
      ++currentCount;
    } else {
      maxCount = std::max(maxCount, currentCount);
      currentCount = 0;
    }
  }

  return std::max(maxCount, currentCount);
}

int main() {
  std::vector<int> v1 {1,1,0,1,1,1};
  printSuccess(findMaxConsecutiveOnes(v1) == 3);

  std::vector<int> v2 {1, 0, 1, 1, 0, 1};
  printSuccess(findMaxConsecutiveOnes(v2) == 2);

  return 0;
}
