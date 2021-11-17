#include <iostream>
#include <limits>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

int minDepth(TreeNode* root) {
  if (!root) {
    return 0;
  }
  int left = minDepth(root->left);
  int right = minDepth(root->right);
  if (left && right) {
    return std::min(left, right) + 1;
  } else if (left && !right) {
    return left + 1;
  } else {
    return right + 1;
  }
}

int main() {
  TreeNode* a7 = new TreeNode(7);
  TreeNode* a15 = new TreeNode(15);
  TreeNode* a20 = new TreeNode(20, a15, a7);
  TreeNode* a9 = new TreeNode(9);
  TreeNode* a3 = new TreeNode(3, a9, a20);
  printSuccess(minDepth(a3) == 2);

  TreeNode* b6 = new TreeNode(6);
  TreeNode* b5 = new TreeNode(5, nullptr, b6);
  TreeNode* b4 = new TreeNode(4, nullptr, b5);
  TreeNode* b3 = new TreeNode(3, nullptr, b4);
  TreeNode* b2 = new TreeNode(2, nullptr, b3);
  printSuccess(minDepth(b2) == 5);

  printSuccess(minDepth(nullptr) == 0);

  return 0;
}
