#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

int countPairs(std::vector<int>& nums, int k) {
  int numPairs = 0;
  int size = nums.size();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (nums[i] == nums[j] && i * j % k == 0) {
        ++numPairs;
      }
    }
  }
  return numPairs;
}

int main() {
  std::vector<int> v1 { 3, 1, 2, 2, 2, 1, 3 };
  int p1 = countPairs(v1, 2);
  printSuccess(p1 == 4);

  std::vector<int> v2 { 1, 2, 3, 4 };
  int p2 = countPairs(v2, 1);
  printSuccess(p2 == 0);

  return 0;
}
