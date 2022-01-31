#include <iostream>
#include <vector>
#include <algorithm>
#include "../../utilities/print-success.cpp"

// int missingNumber(std::vector<int>& nums) {
//   std::sort(nums.begin(), nums.end());
//   int size = nums.size();
//   if (nums[0] != 0) return 0;
//   for (int i = 0; i < size; ++i) {
//     if (i < size - 1 && nums[i] + 1 != nums[i + 1]) {
//       return nums[i] + 1;
//     }
//   }
//   return nums[size - 1] + 1;
// }

int missingNumber(std::vector<int>& nums) {
  int max = 0, sum = 0;
  bool hasZero = false;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] > max) {
      max = nums[i];
    }
    if (!nums[i]) {
      hasZero = true;
    }
    sum += nums[i];
  }
  int maxSum = (max * (max + 1)) / 2;
  if (maxSum == sum) {
    return hasZero ? max + 1 : 0;
  }
  return maxSum - sum;
}

int main() {
  std::vector<int> v1 { 3, 0, 1 };
  std::cout << missingNumber(v1) << "\n";
  printSuccess(missingNumber(v1) == 2);

  std::vector<int> v2 { 0, 1 };
  std::cout << missingNumber(v2) << "\n";
  printSuccess(missingNumber(v2) == 2);

  std::vector<int> v3 { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
  std::cout << missingNumber(v3) << "\n";
  printSuccess(missingNumber(v3) == 8);

  std::vector<int> v4 { 0 };
  std::cout << missingNumber(v4) << "\n";
  printSuccess(missingNumber(v4) == 1);

  std::vector<int> v5 { 1 };
  std::cout << missingNumber(v5) << "\n";
  printSuccess(missingNumber(v5) == 0);

  std::vector<int> v6 { 1, 0 };
  std::cout << missingNumber(v6) << "\n";
  printSuccess(missingNumber(v6) == 2);

  return 0;
}
