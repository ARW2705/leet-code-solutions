#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int getIslandArea(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& visited, int row, int col) {
  int area = 0;
  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(row, col));

  while (!q.empty()) {
    std::pair<int, int> coords = q.front();
    q.pop();
    if (visited[coords.first][coords.second] == 0 && grid[coords.first][coords.second] == 1) {
      ++area;
      visited[coords.first][coords.second] = 1;
      if (coords.first > 0) {
        q.push(std::make_pair(coords.first - 1, coords.second));
      }
      if (coords.first < grid.size() - 1) {
        q.push(std::make_pair(coords.first + 1, coords.second));
      }
      if (coords.second > 0) {
        q.push(std::make_pair(coords.first, coords.second - 1));
      }
      if (coords.second < grid[0].size() - 1) {
        q.push(std::make_pair(coords.first, coords.second + 1));
      }
    }
  }
  return area;
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
  int maxArea = 0, currentArea = 0;
  std::vector<std::vector<int>> visited(grid.size(), std::vector<int>(grid[0].size()));

  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (grid[i][j] == 1 && visited[i][j] == 0) {
        currentArea = getIslandArea(grid, visited, i, j);
        if (currentArea > maxArea) {
          maxArea = currentArea;
        }
      }
    }
  }
  return maxArea;
}

int main() {
  std::vector<std::vector<int>> v1 {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
  };
  int e1 = 6;
  int r1 = maxAreaOfIsland(v1);
  std::cout << r1 << ": " << (r1 == e1 ? "PASS" : "FAIL") << "\n";
  return 0;
}
