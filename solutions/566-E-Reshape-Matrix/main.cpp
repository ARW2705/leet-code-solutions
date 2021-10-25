#include <iostream>
#include <vector>
#include "../../utilities/print-matrix.cpp"

std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
  if ((r * c) != mat.size() * mat[0].size()) {
    return mat;
  }
  std::vector<std::vector<int>> reshaped;
  std::vector<int> tempVector;
  int itemCount = 1;
  for (int i = 0; i < mat.size(); ++i) {
    for (int j = 0; j < mat[i].size(); ++j) {
      tempVector.push_back(mat[i][j]);
      if (itemCount > 0 && itemCount % c == 0) {
        reshaped.push_back(tempVector);
        tempVector.clear();
      }
      ++itemCount;
    }
  }
  return reshaped;
}

int main() {
  std::vector<std::vector<int>> test1 { { 1, 2 }, { 3, 4 } };
  std::vector<std::vector<int>> expected1 { { 1, 2, 3, 4} };
  int r1 = 1, c1 = 4;
  std::vector<std::vector<int>> result1 = matrixReshape(test1, r1, c1);
  printMatrix(result1);

  std::vector<std::vector<int>> test2 { { 1, 2 }, { 3, 4 } };
  std::vector<std::vector<int>> expected2 { { 1, 2 }, { 3, 4 } };
  int r2 = 2, c2 = 4;
  std::vector<std::vector<int>> result2 = matrixReshape(test2, r2, c2);
  printMatrix(result2);

  return 0;
}
