#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

int findCenter(std::vector<std::vector<int>>& edges) {
  int first = edges[0][0];
  int second = edges[0][1];
  int third = edges[1][0];
  int fourth = edges[1][1];
  if (first == third || first == fourth) return first;
  return second;
}

int main() {
  std::vector<std::vector<int>> g1 {{1,2},{2,3},{4,2}};
  printSuccess(findCenter(g1) == 2);

  std::vector<std::vector<int>> g2 {{1,2},{5,1},{1,3},{1,4}};
  printSuccess(findCenter(g2) == 1);

  return 0;
}
