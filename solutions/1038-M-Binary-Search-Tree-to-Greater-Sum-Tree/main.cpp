#include <iostream>
#include <vector>
#include <limits>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/build-binary-tree.cpp"
#include "../../utilities/print-binary-tree.cpp"
#include "../../utilities/print-vector.cpp"

int bstToGstHelper(TreeNode* node, int parentVal) {
  if (!node) return 0;

  int rightSum = bstToGstHelper(node->right, parentVal);
  node->val += std::max(parentVal, rightSum);
  int leftSum = bstToGstHelper(node->left, node->val);
  return std::max(node->val, leftSum);
}

TreeNode* bstToGst(TreeNode* root) {
  if (!root) return root;
  bstToGstHelper(root, 0);
  return root;
}

int main() {
  long long null = getNullSentinel();

  std::vector<long long> v1 { 4, 1, 6, 0, 2, 5, 7, null, null, null, 3, null, null, null, 8 };
  TreeNode* root1 = buildBinaryTree(v1);
  TreeNode* g1 = bstToGst(root1);
  printBinaryTree(g1);
  std::cout << "\n";

  std::vector<long long> v2 { 0, null, 1 };
  TreeNode* root2 = buildBinaryTree(v2);
  TreeNode* g2 = bstToGst(root2);
  printBinaryTree(g2);
  std::cout << "\n";

  return 0;
}
