#include <iostream>
#include <vector>
#include <map>
#include "../../utilities/print-success.cpp"

int singleNumber(std::vector<int>& nums) {
  std::map<int, int> counts;
  for (int num : nums) {
    ++counts[num];
  }
  for (std::map<int, int>::iterator iter = counts.begin(); iter != counts.end(); ++iter) {
    if (iter->second == 1) {
      return iter->first;
    }
  }
  return -1;
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
