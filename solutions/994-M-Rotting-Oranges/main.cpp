#include <iostream>
#include <vector>
#include <queue>
#include "../../utilities/print-matrix.cpp"
#include "../../utilities/compare-matrices.cpp"

int enqueueNeighbors(std::queue<std::pair<int, int>>& q, std::vector<std::vector<int>>& grid, int row, int col) {
  std::vector<std::pair<int, int>> neighbors { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
  int newBlockCount = 0;
  int newRow;
  int newCol;
  for (auto neighbor : neighbors) {
    newRow = row + neighbor.first;
    newCol = col + neighbor.second;
    if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[row].size() && grid[newRow][newCol] == 1) {
      grid[newRow][newCol] = 2;
      q.push({ newRow, newCol });
      ++newBlockCount;
    }
  }
  return newBlockCount;
}

int orangesRotting(std::vector<std::vector<int>>& grid) {
  std::queue<std::pair<int, int>> q;
  int freshOrangeCount = 0;
  for (size_t row = 0; row < grid.size(); ++row) {
    for (size_t col = 0; col < grid[row].size(); ++col) {
      if (grid[row][col] == 1) {
        ++freshOrangeCount;
      } else if (grid[row][col] == 2) {
        q.push({ row, col });
      }
    }
  }
  if (!freshOrangeCount) {
    return 0;
  }

  int minutes = -1;
  int blockSize = q.size();
  int nextBlock = 0;
  while (!q.empty()) {
    for (int i = 0; i < blockSize; ++i) {
      std::pair<int, int> rotten = q.front();
      q.pop();
      nextBlock += enqueueNeighbors(q, grid, rotten.first, rotten.second);
    }
    blockSize = nextBlock;
    freshOrangeCount -= blockSize;
    nextBlock = 0;
    ++minutes;
  }
  return freshOrangeCount == 0 ? minutes : -1;
}

int main() {
  std::vector<std::vector<int>> g1 {
    { 2, 1, 1 },
    { 1, 1, 0 },
    { 0, 1, 1 }
  };
  int e1 = 4;
  int r1 = orangesRotting(g1);
  std::cout << "expected 4, got " << r1 << ": " << (e1 == r1 ? "PASS" : "FAIL") << "\n\n";

  std::vector<std::vector<int>> g2 {
    { 2, 1, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 }
  };
  int e2 = -1;
  int r2 = orangesRotting(g2);
  std::cout << "expected -1, got " << r2 << ": " << (e2 == r2 ? "PASS" : "FAIL") << "\n\n";

  std::vector<std::vector<int>> g3 {
    { 0, 2 }
  };
  int e3 = 0;
  int r3 = orangesRotting(g3);
  std::cout << "expected 0, got " << r3 << ": " << (e3 == r3 ? "PASS" : "FAIL") << "\n\n";

  std::vector<std::vector<int>> g4 {
    { 1, 2 }
  };
  int e4 = 1;
  int r4 = orangesRotting(g4);
  std::cout << "expected 1, got " << r4 << ": " << (e4 == r4 ? "PASS" : "FAIL") << "\n";

  std::cout << std::endl;
  return 0;
}
