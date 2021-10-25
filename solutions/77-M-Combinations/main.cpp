#include <iostream>
#include <vector>
#include "../../utilities/print-matrix.cpp"

void combineHelper(std::vector<std::vector<int>>& matrix, std::vector<int>& combination, int n, int k) {
  if (k == 0) {
    matrix.push_back(combination);
  } else {
    for (int num = n; num > 0; --num) {
      combination.push_back(num);
      combineHelper(matrix, combination, num - 1, k - 1);
      combination.pop_back();
    }
  }
}

std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<int>> m;
  std::vector<int> combination;
  combineHelper(m, combination, n, k);
  return m;
}

int main() {
  int n1 = 4;
  int k1 = 2;
  std::vector<std::vector<int>> r1 = combine(n1, k1);
  printMatrix(r1);

  return 0;
}
