#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

// int findTargetSumWaysHelper(std::vector<int>& nums, int target, int sum, int index) {
//   int count = 0;
//   if (target == sum) {
//     ++count;
//   }
//   for (int i = index; i < nums.size(); ++i) {
//     nums[i] *= -1;
//     count += findTargetSumWaysHelper(nums, target, sum + 2 * nums[i], i + 1);
//     nums[i] *= -1;
//   }
//   return count;
// }
//
// int findTargetSumWays(std::vector<int>& nums, int target) {
//   int sum = 0;
//   for (int num : nums) {
//     sum += num;
//   }
//   int count = findTargetSumWaysHelper(nums, target, sum, 0);
//   std::cout << "found " << count << " ways\n";
//   return count;
// }

int findTargetSumWaysHelper(std::vector<int>& nums, int target, int sum, int index, std::vector<std::vector<int>>& memo) {
  int count = 0;
  if (target == sum) {
    ++count;
  }
  for (int i = index; i < nums.size(); ++i) {
    int trySum = sum + -2 * nums[i] + 1000;
    if (memo[i][trySum] != -1) {
      count += memo[i][trySum];
    } else {
      nums[i] *= -1;
      int subCount = findTargetSumWaysHelper(nums, target, sum + 2 * nums[i], i + 1, memo);
      memo[i][trySum] = subCount;
      count += subCount;
      nums[i] *= -1;
    }
  }
  return count;
}

int findTargetSumWays(std::vector<int>& nums, int target) {
  int sum = 0;
  for (int num : nums) {
    sum += num;
  }
  std::vector<std::vector<int>> memo(21, std::vector<int>(2001, -1));
  int count = findTargetSumWaysHelper(nums, target, sum, 0, memo);
  return count;
}

int main() {
  std::vector<int> v1 { 1, 1, 1, 1, 1 };
  printSuccess(findTargetSumWays(v1, 3) == 5);

  std::vector<int> v2 { 1 };
  printSuccess(findTargetSumWays(v2, 1) == 1);

  std::vector<int> v3 { 1, 0 };
  printSuccess(findTargetSumWays(v3, 1) == 2);

  std::vector<int> v4 { 0, 2, 2, 4 };
  printSuccess(findTargetSumWays(v4, 4) == 4);

  std::vector<int> v5 {2,7,9,13,27,31,37,3,2,3,5,7,11,13,17,19,23,29,47,53};
  printSuccess(findTargetSumWays(v5, 127) == 0);


  return 0;
}
