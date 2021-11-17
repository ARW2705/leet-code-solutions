#include <iostream>
#include <vector>
#include <map>
#include "../../utilities/print-success.cpp"

int majorityElement(std::vector<int>& nums) {
  std::map<int, int> numCount;
  for (int num : nums) {
    ++numCount[num];
  }
  int maxElement;
  int maxCount = 0;
  for (std::map<int, int>::iterator iter = numCount.begin(); iter != numCount.end(); ++iter) {
    if (iter->second > maxCount) {
      maxElement = iter->first;
      maxCount = iter->second;
    }
  }
  return maxElement;
}

int main() {
  std::vector<int> v1 { 3, 2, 3 };
  printSuccess(majorityElement(v1) == 3);

  std::vector<int> v2 { 2, 2, 1, 1, 1, 2, 2 };
  printSuccess(majorityElement(v2) == 2);
  return 0;
}
