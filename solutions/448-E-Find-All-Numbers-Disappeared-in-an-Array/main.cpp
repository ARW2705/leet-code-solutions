#include <iostream>
#include <vector>
#include "../../utilities/print-vector.cpp"

// Using second vector
// std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
//   int size = nums.size();
//   std::vector<int> result;
//   std::vector<int> expected(size, 0);
//   for (int num : nums) {
//     expected[num - 1] = num;
//   }
//   for (int i = 0; i < size; ++i) {
//     if (expected[i] == 0) {
//       result.push_back(i + 1);
//     }
//   }
//   return result;
// }

// In place
std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
  int size = nums.size();
  for (int i = 0; i < size; ++i) {
    nums[std::abs(nums[i]) - 1] = -std::abs(nums[std::abs(nums[i]) - 1]);
  }

  std::vector<int> result;
  for (int i = 0; i < size; ++i) {
    if (nums[i] > 0) {
      result.push_back(i + 1);
    }
  }
  return result;
}

int main() {
  std::vector<int> v1 { 4, 3, 2, 7, 8, 2, 3, 1 };
  std::vector<int> r1 = findDisappearedNumbers(v1);
  printVector(r1);

  std::vector<int> v2 { 1, 1 };
  std::vector<int> r2 = findDisappearedNumbers(v2);
  printVector(r2);

  return 0;
}
