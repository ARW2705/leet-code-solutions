#include <iostream>
#include <vector>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

// std::vector<int> runningSum(std::vector<int>& nums) {
//   int size = nums.size();
//   std::vector<int> result(size);
//   int sumSoFar = 0;
//   for (int i = 0; i < size; ++i) {
//     sumSoFar += nums[i];
//     result[i] = sumSoFar;
//   }
//   return result;
// }

std::vector<int> runningSum(std::vector<int>& nums) {
  for (int i = 1; i < nums.size(); ++i) {
    nums[i] += nums[i - 1];
  }
  return nums;
}

int main() {
  std::vector<int> v1 { 1, 2, 3, 4 };
  std::vector<int> e1 { 1, 3, 6, 10 };
  std::vector<int> r1 = runningSum(v1);
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 { 1, 1, 1, 1, 1 };
  std::vector<int> e2 { 1, 2, 3, 4, 5 };
  std::vector<int> r2 = runningSum(v2);
  printSuccess(compareVector(e2, r2));

  return 0;
}
