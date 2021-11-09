#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

int minimumTotal(std::vector<std::vector<int>>& triangle) {
  if (triangle.size() > 1) {
    for (int i = triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j < triangle[i].size(); ++j) {
        triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
      }
    }
  }
  return triangle[0][0];
}

int main() {
  std::vector<std::vector<int>> t1 {
    { 2 },
    { 3, 4 },
    { 6, 5, 7 },
    { 4, 1, 8, 3 }
  };
  printSuccess(minimumTotal(t1) == 11);

  std::vector<std::vector<int>> t2 { { -10 } };
  printSuccess(minimumTotal(t2) == -10);

  return 0;
}
