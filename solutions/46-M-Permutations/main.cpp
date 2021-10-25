#include <iostream>
#include <vector>
#include "../../utilities/print-matrix.cpp"

void permuteHelper(std::vector<int>& nums, std::vector<std::vector<int>>& permutations, std::vector<int>& current) {
  size_t size = nums.size();
  if (size == 0) {
    permutations.push_back(current);
  } else {
    int currentValue;
    for (size_t i = 0; i < size; ++i) {
      currentValue = nums[i];
      current.push_back(currentValue);
      nums.erase(nums.begin() + i);
      permuteHelper(nums, permutations, current);
      current.pop_back();
      nums.insert(nums.begin() + i, currentValue);
    }
  }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
  std::vector<std::vector<int>> permutations;
  std::vector<int> current;
  permuteHelper(nums, permutations, current);
  return permutations;
}

int main() {
  std::vector<int> v1 { 1, 2, 3 };
  std::vector<std::vector<int>> e1 {
    {1,2,3},
    {1,3,2},
    {2,1,3},
    {2,3,1},
    {3,1,2},
    {3,2,1}
  };
  std::vector<std::vector<int>> r1 = permute(v1);
  printMatrix(r1);

  return 0;
}
