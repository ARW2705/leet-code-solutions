#include <iostream>
#include <vector>
#include <set>
#include "../../utilities/print-success.cpp"

int singleNumber(std::vector<int>& nums) {
  std::set<int> previousNums;
  for (int i = 0; i < nums.size(); ++i) {
    if (previousNums.find(nums[i]) == previousNums.end()) {
      previousNums.insert(nums[i]);
    } else {
      previousNums.erase(nums[i]);
    }
  }
  return *(previousNums.begin());
}

int main() {
  std::vector<int> v1 { 2, 2, 1 };
  printSuccess(singleNumber(v1) == 1);

  std::vector<int> v2 { 4, 1, 2, 1, 2 };
  printSuccess(singleNumber(v2) == 4);

  std::vector<int> v3 { 1 };
  printSuccess(singleNumber(v3) == 1);

  return 0;
}
