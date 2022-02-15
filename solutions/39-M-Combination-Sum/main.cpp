#include <iostream>
#include <vector>
#include <algorithm>
#include "../../utilities/print-matrix.cpp"

int shortcircuit = 0;

void combinationSumHelper(std::vector<int>& candidates, int target, int startIndex, std::vector<int>& current, std::vector<std::vector<int>>& combos) {
  if (target == 0) {
    combos.push_back(current);
  } else if (target > 0) {
    for (int i = startIndex; i < candidates.size(); ++i) {
      current.push_back(candidates[i]);
      combinationSumHelper(candidates, target - candidates[i], i, current, combos);
      current.pop_back();
    }
  }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<std::vector<int>> combos;
  std::vector<int> current;
  combinationSumHelper(candidates, target, 0, current, combos);
  return combos;
}

int main() {
  std::vector<int> v1 { 2, 3, 6, 7 };
  std::vector<std::vector<int>> r1 = combinationSum(v1, 7);
  printMatrix(r1);

  std::vector<int> v2 { 2, 3, 5 };
  std::vector<std::vector<int>> r2 = combinationSum(v2, 8);
  printMatrix(r2);

  std::vector<int> v3 { 2 };
  std::vector<std::vector<int>> r3 = combinationSum(v3, 1);
  printMatrix(r3);
  return 0;
}
