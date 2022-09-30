#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-matrices.cpp"

void explore(std::vector<std::vector<int>>& graph, int currentNode, int targetNode, std::vector<int>& path, std::vector<std::vector<int>>& paths) {
  if (currentNode >= graph.size()) return;

  path.push_back(currentNode);
  for (int i = 0; i < graph[currentNode].size(); ++i) {
    explore(graph, graph[currentNode][i], targetNode, path, paths);
  }

  if (currentNode == targetNode) {
    paths.push_back(path);
  }
  
  path.pop_back();
}

std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
  std::vector<std::vector<int>> paths;
  std::vector<int> path;
  explore(graph, 0, graph.size() - 1, path, paths);
  return paths;
}

int main() {
  std::vector<std::vector<int>> g1 {
    { 1, 2 },
    { 3 },
    { 3 },
    { }
  };
  std::vector<std::vector<int>> e1 {
    { 0, 1, 3 },
    { 0, 2, 3 }
  };
  std::vector<std::vector<int>> r1 = allPathsSourceTarget(g1);
  printSuccess(compareMatrices(e1, r1));

  std::vector<std::vector<int>> g2 {
    {4,3,1},
    {3,2,4},
    {3},
    {4},
    {}
  };
  std::vector<std::vector<int>> e2 {
    {0,4},
    {0,3,4},
    {0,1,3,4},
    {0,1,2,3,4},
    {0,1,4}
  };
  std::vector<std::vector<int>> r2 = allPathsSourceTarget(g2);
  printSuccess(compareMatrices(e2, r2));

  return 0;
}
