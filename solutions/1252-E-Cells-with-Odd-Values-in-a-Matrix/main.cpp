#include <iostream>
#include <vector>

int oddCells(int n, int m, std::vector<std::vector<int>>& indices) {
  std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 0));
    int totalOdds = 0;
    for (auto v : indices) {
      for (int i=0; i < m; ++i) {
        totalOdds += ++matrix[v[0]][i] % 2 == 0 ? -1: 1;
      }
      for (int i=0; i < n; ++i) {
        totalOdds += ++matrix[i][v[1]] % 2 == 0 ? -1: 1;
      }
    }
    return totalOdds;
}

int main() {
  std::vector<std::vector<int>> m1 = {
    { 0, 1 },
    { 1, 1 }
  };
  std::cout << "Test 1: " << oddCells(2, 3, m1) << "\n";

  std::vector<std::vector<int>> m2 = {
    { 1, 1 },
    { 0, 0 }
  };
  std::cout << "Test 2: " << oddCells(2, 2, m2) << "\n";
  return 0;
}
