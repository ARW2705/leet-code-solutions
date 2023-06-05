#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-matrices.cpp"
#include "../../utilities/print-matrix.cpp"

int findLargestInBlock(std::vector<std::vector<int>>& grid, int row, int col) {
  int largest = -1;
  for (int i = row - 1; i < row + 2; ++i) {
    for (int j = col - 1; j < col + 2; ++j) {
      largest = std::max(largest, grid[i][j]);
    }
  }
  return largest;
}

std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
  std::vector<std::vector<int>> largestLocals(grid.size() - 2, std::vector<int>(grid.size() - 2, 0));

  for (int row = 1; row < grid.size() - 1; ++row) {
    for (int col = 1; col < grid[row].size() - 1; ++col) {
      largestLocals[row - 1][col - 1] = findLargestInBlock(grid, row, col);
    }
  }

  return largestLocals;
}

int main() {
  std::vector<std::vector<int>> m1 {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
  std::vector<std::vector<int>> e1 {{9,9},{8,6}};
  std::vector<std::vector<int>> r1 = largestLocal(m1);
  printMatrix(r1);
  printSuccess(compareMatrices(e1, r1));

  std::vector<std::vector<int>> m2 {{1,1,1,1,1},{1,1,1,1,1},{1,1,2,1,1},{1,1,1,1,1},{1,1,1,1,1}};
  std::vector<std::vector<int>> e2 {{2,2,2},{2,2,2},{2,2,2}};
  std::vector<std::vector<int>> r2 = largestLocal(m2);
  printMatrix(r2);
  printSuccess(compareMatrices(e2, r2));

  return 0;
}
