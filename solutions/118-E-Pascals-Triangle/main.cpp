#include <iostream>
#include <vector>
#include "../../utilities/print-matrix.cpp"

std::vector<std::vector<int>> generate(int numRows) {
  std::vector<std::vector<int>> result;
  std::vector<int> tempVector;
  for (int i = 1; i < numRows + 1; ++i) {
    for (int j = 0; j < i; ++j) {
      if (j == 0 || j == i - 1) {
        tempVector.push_back(1);
      } else if (i > 1) {
        tempVector.push_back(result[i - 2][j - 1] + result[i - 2][j]);
      }
    }
    result.push_back(tempVector);
    tempVector.clear();
  }
  return result;
}

int main() {
  std::vector<std::vector<int>> result1 = generate(5);
  std::vector<std::vector<int>> expected1 {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
  printMatrix(result1);

  std::vector<std::vector<int>> result2 = generate(1);
  std::vector<std::vector<int>> expected2 {{1}};
  printMatrix(result2);

  std::cout << std::endl;
  return 0;
}
