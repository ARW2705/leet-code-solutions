#include <iostream>
#include <vector>
#include <algorithm>

int arrayPairSum(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  int total = 0;
  for (int i=0; i < nums.size(); i += 2) {
    total += nums[i];
  }
  return total;
}

int main() {
  std::vector<int> array1 { 1, 4, 3, 2 };
  int pairSum1 = arrayPairSum(array1);
  std::cout
    << "For array [1, 4, 3, 2] the max sum of min of pairs is "
    <<  pairSum1
    << (pairSum1 == 4 ? "\nPASS\n": "\nFail\n");

  std::vector<int> array2 { 1, 1 };
  int pairSum2 = arrayPairSum(array2);
  std::cout << "For array [1, 1] the max sum of min of pairs is "
    <<  pairSum2
    << (pairSum2 == 1 ? "\nPASS\n": "\nFail\n");
  return 0;
}
