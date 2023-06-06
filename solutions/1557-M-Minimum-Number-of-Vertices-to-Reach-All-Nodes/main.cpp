#include <iostream>
#include <vector>
#include "../../utilities/print-vector.cpp"
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
  vector<int> ends(n, 0);
  for (auto edge : edges) {
    ++ends[edge[1]];
  }

  vector<int> vertices;
  for (int i = 0; i < ends.size(); ++i) {
    if (ends[i] == 0) {
      vertices.push_back(i);
    }
  }
  
  return vertices;
}

int main() {
  vector<vector<int>> m1 {
    { 0, 1 },
    { 0, 2 },
    { 2, 5 },
    { 3, 4 },
    { 4, 2 }
  };
  vector<int> e1 { 0, 3 };
  vector<int> r1 = findSmallestSetOfVertices(6, m1);
  printVector(r1);
  printSuccess(compareVector(r1, e1));

  vector<vector<int>> m2 {
    { 0, 1 },
    { 2, 1 },
    { 3, 1 },
    { 1, 4 },
    { 2, 4 }
  };
  vector<int> e2 { 0, 2, 3 };
  vector<int> r2 = findSmallestSetOfVertices(5, m2);
  printVector(r2);
  printSuccess(compareVector(r2, e2));

  return 0;
}
