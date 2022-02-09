#include <iostream>
#include <vector>
#include <algorithm>
#include "../../utilities/print-matrix.cpp"

// std::string stringify(std::vector<int>& nums) {
//   std::string s = "";
//   for (int num : nums) {
//     s += std::to_string(num);
//   }
//   return s;
// }
//
// void combinationSum2Helper(std::vector<int>& candidates, int target, int startIndex, std::vector<int>& current, std::unordered_set<std::string>& previous, std::vector<std::vector<int>>& combos) {
//   if (target == 0) {
//     std::string s = stringify(current);
//     if (previous.find(s) == previous.end()) {
//       combos.push_back(current);
//       previous.insert(s);
//     }
//   } else if (target > 0) {
//     for (int i = startIndex; i < candidates.size(); ++i) {
//       if (target - candidates[i] < 0) return;
//       current.push_back(candidates[i]);
//       combinationSum2Helper(candidates, target - candidates[i], i + 1, current, previous, combos);
//       current.pop_back();
//     }
//   }
// }
//
// std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
//   std::vector<std::vector<int>> combos;
//   std::unordered_set<std::string> previous;
//   std::sort(candidates.begin(), candidates.end());
//   std::vector<int> current;
//   combinationSum2Helper(candidates, target, 0, current, previous, combos);
//   return combos;
// }

void combinationSum2Helper(std::vector<int>& candidates, int target, int startIndex, std::vector<int>& current, std::vector<std::vector<int>>& combos) {
  if (target == 0) {
    combos.push_back(current);
  } else if (target > 0) {
    for (int i = startIndex; i < candidates.size(); ++i) {
      if (i == startIndex || candidates[i] != candidates[i - 1]) {
        current.push_back(candidates[i]);
        combinationSum2Helper(candidates, target - candidates[i], i + 1, current, combos);
        current.pop_back();
      }
    }
  }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<std::vector<int>> combos;
  std::vector<int> current;
  combinationSum2Helper(candidates, target, 0, current, combos);
  return combos;
}

int main() {
  std::vector<int> v1 { 10, 1, 2, 7, 6, 1, 5 };
  std::vector<std::vector<int>> r1 = combinationSum2(v1, 8);
  printMatrix(r1);

  std::vector<int> v2 { 2, 5, 2, 1, 2 };
  std::vector<std::vector<int>> r2 = combinationSum2(v2, 5);
  printMatrix(r2);

  std::vector<int> v3 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  std::vector<std::vector<int>> r3 = combinationSum2(v3, 30);
  printMatrix(r3);

  return 0;
}
