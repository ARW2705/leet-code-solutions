#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include "../../utilities/print-success.cpp"

// DP
// int minPathSum(std::vector<std::vector<int>>& grid) {
//   int mSize = grid.size();
//   int nSize = grid[0].size();
//   std::vector<std::vector<int>> paths(mSize, std::vector<int>(nSize, 0));
//   paths[0][0] = grid[0][0];

//   int minPathSoFar;
//   for (int row = 0; row < mSize; ++row) {
//     for (int col = 0; col < nSize; ++col) {
//       if (row == 0 && col == 0) continue;

//       if (row == 0 || col == 0) {
//         minPathSoFar = row == 0 ? paths[row][col - 1] : paths[row - 1][col];
//       } else {
//         minPathSoFar = std::min(paths[row - 1][col], paths[row][col - 1]);
//       }
//       paths[row][col] += grid[row][col] + minPathSoFar;
//     }
//   }

//   return paths[mSize - 1][nSize - 1];
// }

// BFS
int minPathSum(std::vector<std::vector<int>>& grid) {
  std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
  std::queue<std::pair<int, int>> q;
  visited[0][0] = true;
  q.push({ 0, 0 });

  int row, col, fromUp, fromLeft, infinity = std::numeric_limits<int>::max();
  while (!q.empty()) {
    std::pair<int, int> cell = q.front();
    q.pop();
    row = cell.first;
    col = cell.second;
    
    if (row != 0 || col != 0) {
      fromUp = row > 0 ? grid[row - 1][col] : infinity;
      fromLeft = col > 0 ? grid[row][col - 1] : infinity;
      grid[row][col] += std::min(fromUp, fromLeft);
    }

    if (row < grid.size() - 1 && !visited[row + 1][col]) {
      visited[row + 1][col] = true;
      q.push({ row + 1, col });
    }

    if (col < grid[row].size() - 1 && !visited[row][col + 1]) {
      visited[row][col + 1] = true;
      q.push({ row, col + 1 });
    }
  }

  return grid[grid.size() - 1][grid[0].size() - 1];
}

int main() {
  std::vector<std::vector<int>> m1 {{1,3,1},{1,5,1},{4,2,1}};
  printSuccess(minPathSum(m1) == 7);

  std::vector<std::vector<int>> m2 {{1,2,3},{4,5,6}};
  printSuccess(minPathSum(m2) == 12);

  return 0;
}
