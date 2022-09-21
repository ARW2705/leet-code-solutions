#include <iostream>
#include <vector>
#include "../../utilities/compare-matrices.cpp"
#include "../../utilities/print-success.cpp"

void rotate(std::vector<std::vector<int>>& matrix) {
  int size = matrix.size();
  int mid = size / 2;
  int numSteps;
  for (int layer = 0; layer < mid; ++layer) {
    numSteps = size - (2 * layer) - 1;
    for (int shift = 0; shift < numSteps; ++shift) {
      std::swap(matrix[layer][layer + shift], matrix[layer + numSteps - shift][layer]);
      std::swap(matrix[layer + numSteps - shift][layer], matrix[layer + numSteps][layer + numSteps - shift]);
      std::swap(matrix[layer + numSteps][layer + numSteps - shift], matrix[layer + shift][layer + numSteps]);
    }
  }
}

int main() {
  std::vector<std::vector<int>> m1 {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
  };
  std::vector<std::vector<int>> e1 {
    { 7, 4, 1 },
    { 8, 5, 2 },
    { 9, 6, 3 }
  };
  rotate(m1);
  printSuccess(compareMatrices(m1, e1));

  std::vector<std::vector<int>> m2 {
    { 5,  1,  9,  11 },
    { 2,  4,  8,  10 },
    { 13, 3,  6,  7  },
    { 15, 14, 12, 16 }
  };
    std::vector<std::vector<int>> e2 {
    { 15, 13, 2,  5  },
    { 14, 3,  4,  1  },
    { 12, 6,  8,  9  },
    { 16, 7,  10, 11 }
  };
  rotate(m2);
  printSuccess(compareMatrices(m2, e2));

  return 0;
}
