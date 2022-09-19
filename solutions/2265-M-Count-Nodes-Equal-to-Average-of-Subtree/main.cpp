#include <iostream>
#include <utility>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

std::pair<int, int> averageOfSubtreeHelper(TreeNode* node, int& numNodes) {
  if (!node) return std::make_pair(0, 0);

  std::pair<int, int> left = averageOfSubtreeHelper(node->left, numNodes);
  std::pair<int, int> right = averageOfSubtreeHelper(node->right, numNodes);
  int totalSum = left.first + right.first + node->val;
  int totalSize = left.second + right.second + 1;
  if (totalSum / totalSize == node->val) {
    ++numNodes;
  }
  return std::make_pair(totalSum, totalSize);
}

int averageOfSubtree(TreeNode* root) {
  int numNodes = 0;
  averageOfSubtreeHelper(root, numNodes);
  return numNodes;
}

int main() {
  TreeNode* n6 = new TreeNode(6);
  TreeNode* n5 = new TreeNode(5, nullptr, n6);
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n0 = new TreeNode(0);
  TreeNode* n8 = new TreeNode(8, n0, n1);
  TreeNode* n4 = new TreeNode(4, n8, n5);
  int numNodes = averageOfSubtree(n4);
  std::cout << numNodes << "\n";
  printSuccess(numNodes == 5);

  return 0;
}
