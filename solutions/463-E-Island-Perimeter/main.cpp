#include <iostream>
#include <vector>
#include <queue>
#include "../../utilities/print-success.cpp"
#include "../../utilities/print-vector.cpp"

// std::pair<int, int> getStartingPoint(std::vector<std::vector<int>>& grid) {
//   for (int row = 0; row < grid.size(); ++row) {
//     for (int col = 0; col < grid[row].size(); ++col) {
//       if (grid[row][col] == 1) {
//         grid[row][col] = 2;
//         return std::make_pair(row, col);
//       }
//     }
//   }
//   return std::make_pair(-1, -1);
// }
//
// int enqueueNeighbors(std::vector<std::vector<int>>& grid, std::queue<std::pair<int, int>>& q, int row, int col) {
//   int edgeCount = 0;
//   if (row <= 0 || grid[row - 1][col] == 0) {
//     ++edgeCount;
//   } else if (row < grid.size() && grid[row - 1][col] == 1) {
//     grid[row - 1][col] = 2;
//     q.push(std::make_pair(row - 1, col));
//   }
//
//   if (row >= grid.size() - 1 || grid[row + 1][col] == 0) {
//     ++edgeCount;
//   } else if (grid[row + 1][col] == 1) {
//     grid[row + 1][col] = 2;
//     q.push(std::make_pair(row + 1, col));
//   }
//
//   if (col <= 0 || grid[row][col - 1] == 0) {
//     ++edgeCount;
//   } else if (grid[row][col - 1] == 1) {
//     grid[row][col - 1] = 2;
//     q.push(std::make_pair(row, col - 1));
//   }
//
//   if (col >= grid[0].size() - 1 || grid[row][col + 1] == 0) {
//     ++edgeCount;
//   } else if (grid[row][col + 1] == 1) {
//     grid[row][col + 1] = 2;
//     q.push(std::make_pair(row, col + 1));
//   }
//
//   return edgeCount;
// }
//
// BFS
// int islandPerimeter(std::vector<std::vector<int>>& grid) {
//   std::queue<std::pair<int, int>> q;
//   q.push(getStartingPoint(grid));
//
//   int edgeCount = 0;
//   while (!q.empty()) {
//     std::pair<int, int> coords = q.front();
//     q.pop();
//     edgeCount += enqueueNeighbors(grid, q, coords.first, coords.second);
//   }
//
//   return edgeCount;
// }

int getCoastCount(std::vector<std::vector<int>>& grid, int row, int col) {
  int coastCount = 0;
  if (row <= 0 || grid[row - 1][col] == 0) {
    ++coastCount;
  }
  if (row >= grid.size() - 1 || grid[row + 1][col] == 0) {
    ++coastCount;
  }
  if (col <= 0 || grid[row][col - 1] == 0) {
    ++coastCount;
  }
  if (col >= grid[0].size() - 1 || grid[row][col + 1] == 0) {
    ++coastCount;
  }
  return coastCount;
}

int islandPerimeter(std::vector<std::vector<int>>& grid) {
  int perimeter = 0;
  int rowSize = grid.size();
  int colSize = grid[0].size();
  for (int row = 0; row < rowSize; ++row) {
    for (int col = 0; col < colSize; ++col) {
      if (grid[row][col] == 1) {
        perimeter += getCoastCount(grid, row, col);
      }
    }
  }
  return perimeter;
}

int main() {
  std::vector<std::vector<int>> g1 {
    { 0, 1, 0, 0 },
    { 1, 1, 1, 0 },
    { 0, 1, 0, 0 },
    { 1, 1, 0, 0 }
  };
  printSuccess(islandPerimeter(g1) == 16);

  std::vector<std::vector<int>> g2 {
    { 1 }
  };
  printSuccess(islandPerimeter(g2) == 4);

  std::vector<std::vector<int>> g3 {
    { 1, 0 }
  };
  printSuccess(islandPerimeter(g3) == 4);

  std::vector<std::vector<int>> g4 {
    { 1, 1 },
    { 1, 1 }
  };
  printSuccess(islandPerimeter(g4) == 8);

  std::vector<std::vector<int>> g5 {
    { 1, 1 }
  };
  printSuccess(islandPerimeter(g5) == 6);

  return 0;
}
