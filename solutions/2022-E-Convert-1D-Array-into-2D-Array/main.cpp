#include <iostream>
#include <vector>
#include "../../utilities/compare-matrices.cpp"
#include "../../utilities/print-success.cpp"

std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
  if (m * n != original.size()) {
    return {};
  }

  std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
  int originalIndex = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      matrix[i][j] = original[originalIndex++];
    }
  }
  return matrix;
}

int main() {
  std::vector<int> v1 { 1, 2, 3, 4 };
  std::vector<std::vector<int>> e1 { { 1, 2 }, { 3, 4 } };
  std::vector<std::vector<int>> r1 = construct2DArray(v1, 2, 2);
  printSuccess(compareMatrices(e1, r1));

  std::vector<int> v2 { 1, 2, 3 };
  std::vector<std::vector<int>> e2 { { 1, 2, 3 } };
  std::vector<std::vector<int>> r2 = construct2DArray(v2, 1, 3);
  printSuccess(compareMatrices(e2, r2));

  std::vector<int> v3 { 1, 2 };
  std::vector<std::vector<int>> e3 { };
  std::vector<std::vector<int>> r3 = construct2DArray(v3, 1, 1);
  printSuccess(compareMatrices(e3, r3));

  std::vector<int> v4 { 1, 1, 1, 1 };
  std::vector<std::vector<int>> e4 { { 1 }, { 1 }, { 1 }, { 1 } };
  std::vector<std::vector<int>> r4 = construct2DArray(v4, 4, 1);
  printSuccess(compareMatrices(e4, r4));

  return 0;
}
