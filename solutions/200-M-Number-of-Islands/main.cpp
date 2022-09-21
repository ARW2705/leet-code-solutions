#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

int exploreIsland(std::vector<std::vector<char>>& grid, int row, int col) {
  if (row < 0 || col < 0 || row > grid.size() - 1 || col > grid[0].size() - 1 || grid[row][col] == '0') return 0;

  grid[row][col] = '0';
  exploreIsland(grid, row - 1, col);
  exploreIsland(grid, row, col - 1);
  exploreIsland(grid, row + 1, col);
  exploreIsland(grid, row, col + 1);
  return 1;
}

int numIslands(std::vector<std::vector<char>>& grid) {
  int islandCount = 0;
  for (int row = 0; row < grid.size(); ++row) {
    for (int col = 0; col < grid[row].size(); ++col) {
      if (grid[row][col] == '1') {
        islandCount += exploreIsland(grid, row, col);
      }
    }
  }
  return islandCount;
}

int main() {
  std::vector<std::vector<char>> m1 {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
  };
  printSuccess(numIslands(m1) == 1);

  std::vector<std::vector<char>> m2 {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
  };
  printSuccess(numIslands(m2) == 3);

  std::vector<std::vector<char>> m3 { { '1' } };
  printSuccess(numIslands(m3) == 1);

  return 0;
}
