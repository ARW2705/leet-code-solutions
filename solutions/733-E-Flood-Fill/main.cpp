#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-vector.cpp"

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(sr, sc));
  std::pair<int, int> coords;
  int previousColor = image[sr][sc];
  std::vector<std::vector<int>> visited(image.size(), std::vector<int>(image[0].size(), 0));

  while(!q.empty()) {
    coords = q.front();
    q.pop();

    if (visited[coords.first][coords.second] == 0 && image[coords.first][coords.second] == previousColor) {
      image[coords.first][coords.second] = newColor;
      if (coords.first > 0) {
        q.push(std::make_pair(coords.first - 1, coords.second));
      }
      if (coords.first < image.size() - 1) {
        q.push(std::make_pair(coords.first + 1, coords.second));
      }
      if (coords.second > 0) {
        q.push(std::make_pair(coords.first, coords.second - 1));
      }
      if (coords.second < image[0].size() - 1) {
        q.push(std::make_pair(coords.first, coords.second + 1));
      }
    }
    visited[coords.first][coords.second] = 1;
  }
  return image;
}

int main() {
  std::vector<std::vector<int>> v1 { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
  int sr1 = 1;
  int sc1 = 1;
  int nc1 = 2;
  std::vector<std::vector<int>> e1 { { 2, 2, 2 }, { 2, 2, 0 }, { 2, 0, 1 } };
  std::vector<std::vector<int>> r1 = floodFill(v1, sr1, sc1, nc1);
  bool ok1 = true;
  for (int i = 0; i < r1.size(); ++i) {
    printVector(r1[i]);
    if (!compareVector(r1[i], e1[i])) {
      ok1 = false;
      break;
    }
  }
  std::cout << (ok1 ? "PASS" : "FAIL") << "\n";

  std::vector<std::vector<int>> v2 { { 0, 0, 0 }, { 0, 0, 0 } };
  int sr2 = 0;
  int sc2 = 0;
  int nc2 = 2;
  std::vector<std::vector<int>> e2 { { 2, 2, 2 }, { 2, 2, 2 } };
  std::vector<std::vector<int>> r2 = floodFill(v2, sr2, sc2, nc2);
  bool ok2 = true;
  for (int i = 0; i < r2.size(); ++i) {
    printVector(r2[i]);
    if (!compareVector(r2[i], e2[i])) {
      ok2 = false;
      break;
    }
  }
  std::cout << (ok2 ? "PASS" : "FAIL") << "\n";

  std::vector<std::vector<int>> v3 { { 0, 0, 0 }, { 0, 1, 1 } };
  int sr3 = 1;
  int sc3 = 1;
  int nc3 = 1;
  std::vector<std::vector<int>> e3 { { 0, 0, 0 }, { 0, 1, 1 } };
  std::vector<std::vector<int>> r3 = floodFill(v3, sr3, sc3, nc3);
  bool ok3 = true;
  for (int i = 0; i < r3.size(); ++i) {
    printVector(r3[i]);
    if (!compareVector(r3[i], e3[i])) {
      ok3 = false;
      break;
    }
  }
  std::cout << (ok3 ? "PASS" : "FAIL") << "\n";
  return 0;
}
