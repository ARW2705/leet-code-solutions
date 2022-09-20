#include <iostream>
#include <vector>
#include "../../utilities/compare-matrices.cpp"
#include "../../utilities/print-success.cpp"

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
  std::vector<std::vector<int>> transposed(matrix[0].size(), std::vector<int>(matrix.size()));
  for (int row = 0; row < matrix.size(); ++row) {
    for (int col = 0; col < matrix[row].size(); ++col) {
      transposed[col][row] = matrix[row][col];
    }
  }
  return transposed;
}

int main() {
  std::vector<std::vector<int>> m1 {{1,2,3},{4,5,6},{7,8,9}};
  std::vector<std::vector<int>> e1 {{1,4,7},{2,5,8},{3,6,9}};
  std::vector<std::vector<int>> r1 = transpose(m1);
  printSuccess(compareMatrices(e1, r1));

  std::vector<std::vector<int>> m2 {{1,2,3},{4,5,6}};
  std::vector<std::vector<int>> e2 {{1,4},{2,5},{3,6}};
  std::vector<std::vector<int>> r2 = transpose(m2);
  printSuccess(compareMatrices(e2, r2));

  return 0;
}
