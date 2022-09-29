#include <iostream>
#include <vector>
#include "../../utilities/print-matrix.cpp"
#include "../../utilities/print-vector.cpp"

void subsetsHelper(std::vector<int>& nums, int start, std::vector<int>& current, std::vector<std::vector<int>>& sets) {
  if (start > nums.size()) return;

  for (int i = start; i < nums.size(); ++i) {
    int num = nums[i];
    current.push_back(num);
    subsetsHelper(nums, i + 1, current, sets);
    sets.push_back(current);
    current.pop_back();
  }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
  std::vector<std::vector<int>> sets { {} };
  std::vector<int> current;
  subsetsHelper(nums, 0, current, sets);
  return sets;
}

int main() {
  std::vector<int> v1 { 1, 2, 3 };
  std::vector<std::vector<int>> r1 = subsets(v1);
  printMatrix(r1);

  std::vector<int> v2 { 0 };
  std::vector<std::vector<int>> r2 = subsets(v2);
  printMatrix(r2);

  return 0;
}
