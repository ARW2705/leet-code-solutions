#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../utilities/print-success.cpp"

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> encounteredNums;
  std::unordered_map<int, int>::iterator iter;
  for (int i = 0; i < nums.size(); ++i) {
    iter = encounteredNums.find(nums[i]);
    if (iter == encounteredNums.end()) {
      encounteredNums.insert(std::make_pair(nums[i], i));
    } else if (i - iter->second <= k) {
      return true;
    } else {
      iter->second = i;
    }
  }
  return false;
}

int main() {
  std::vector<int> v1 { 1, 2, 3, 1 };
  printSuccess(containsNearbyDuplicate(v1, 3));

  std::vector<int> v2 { 1, 0, 1, 1 };
  printSuccess(containsNearbyDuplicate(v2, 1));

  std::vector<int> v3 { 1, 2, 3, 1, 2, 3 };
  printSuccess(!containsNearbyDuplicate(v3, 2));

  return 0;
}
