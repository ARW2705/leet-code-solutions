#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

int getHeight(TreeNode* node) {
  if (node == nullptr) {
    return 0;
  }
  int left = getHeight(node->left);
  int right = getHeight(node->right);
  int diff = std::abs(left - right);
  std::cout << "node=" << node->val << ", l=" << left << ", r=" << right << ", diff=" << diff << "\n";
  if (left == -1 || right == -1 || diff > 1) {
    std::cout << "unbalance\n";
    return -1;
  }
  return std::max(left, right) + 1;
}

bool isBalanced(TreeNode* root) {
  return getHeight(root) != -1;
}

int main() {
  TreeNode* a7 = new TreeNode(7);
  TreeNode* a15 = new TreeNode(15);
  TreeNode* a20 = new TreeNode(20, a15, a7);
  TreeNode* a9 = new TreeNode(9);
  TreeNode* a3 = new TreeNode(3, a9, a20);
  printSuccess(isBalanced(a3));

  TreeNode* b42 = new TreeNode(4);
  TreeNode* b41 = new TreeNode(4);
  TreeNode* b32 = new TreeNode(3);
  TreeNode* b31 = new TreeNode(3, b41, b42);
  TreeNode* b22 = new TreeNode(2);
  TreeNode* b21 = new TreeNode(2, b31, b32);
  TreeNode* b1 = new TreeNode(1, b21, b22);
  printSuccess(!isBalanced(b1));

  TreeNode* c42 = new TreeNode(4);
  TreeNode* c32 = new TreeNode(3, nullptr, c42);
  TreeNode* c22 = new TreeNode(2, nullptr, c32);
  TreeNode* c41 = new TreeNode(4);
  TreeNode* c31 = new TreeNode(3, c41, nullptr);
  TreeNode* c21 = new TreeNode(2, c31, nullptr);
  TreeNode* c1 = new TreeNode(1, c21, c22);
  printSuccess(!isBalanced(c1));

  std::cout << std::endl;

  return 0;
}
