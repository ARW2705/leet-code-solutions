#include <iostream>
#include <vector>
#include <queue>
#include "../../utilities/n-ary-tree-node.hpp"
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-matrices.cpp"

std::vector<std::vector<int>> levelOrder(Node* root) {
  if (!root) return {};

  std::vector<std::vector<int>> result;
  std::vector<int> levelValues;
  std::vector<Node*> nextLevel;
  std::vector<Node*> nodes;
  std::queue<std::vector<Node*>> q;
  q.push({ root });

  while (!q.empty()) {
    nodes = q.front();
    q.pop();
    for (auto node : nodes) {
      levelValues.push_back(node->val);
      for (auto child : node->children) {
        nextLevel.push_back(child);
      }
    }
    if (nextLevel.size()) q.push(nextLevel);
    result.push_back(levelValues);
    nextLevel.clear();
    levelValues.clear();
  }

  return result;
}

int main() {
  Node* n6 = new Node(6);
  Node* n5 = new Node(5);
  Node* n4 = new Node(4);
  Node* n3 = new Node(3, { n5, n6 });
  Node* n2 = new Node(2);
  Node* n1 = new Node(1, { n3, n2, n4 });
  std::vector<std::vector<int>> r1 = levelOrder(n1);
  std::vector<std::vector<int>> e1 = { {1}, {3,2,4}, {5,6} };
  printSuccess(compareMatrices(r1, e1));

  return 0;
}
