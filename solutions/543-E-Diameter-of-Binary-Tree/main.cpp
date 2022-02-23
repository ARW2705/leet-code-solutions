#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

int diameterOfBinaryTreeHelper(TreeNode* root, int& maxPath) {
  if (!root) {
    return 0;
  }
  int left = diameterOfBinaryTreeHelper(root->left, maxPath);
  int right = diameterOfBinaryTreeHelper(root->right, maxPath);
  maxPath = std::max(left + right, maxPath);
  return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
  int maxPath = 0;
  diameterOfBinaryTreeHelper(root, maxPath);
  return maxPath;
}

int main() {
  TreeNode* a5 = new TreeNode(5);
  TreeNode* a4 = new TreeNode(4);
  TreeNode* a3 = new TreeNode(3);
  TreeNode* a2 = new TreeNode(2, a4, a5);
  TreeNode* a1 = new TreeNode(1, a2, a3);
  int r1 = diameterOfBinaryTree(a1);
  std::cout << r1 << " ";
  printSuccess(r1 == 3);

  TreeNode* b2 = new TreeNode(2);
  TreeNode* b1 = new TreeNode(1, b2, nullptr);
  int r2 = diameterOfBinaryTree(b1);
  std::cout << r2 << " ";
  printSuccess(r2 == 1);

  TreeNode* c9 = new TreeNode(9);
  TreeNode* c8 = new TreeNode(8);
  TreeNode* c7 = new TreeNode(7, nullptr, c9);
  TreeNode* c6 = new TreeNode(6, c8, nullptr);
  TreeNode* c5 = new TreeNode(5, nullptr, c7);
  TreeNode* c4 = new TreeNode(4, c6, nullptr);
  TreeNode* c3 = new TreeNode(3);
  TreeNode* c2 = new TreeNode(2, c4, c5);
  TreeNode* c1 = new TreeNode(1, c2, c3);
  int r3 = diameterOfBinaryTree(c1);
  std::cout << r3 << " ";
  printSuccess(r3 == 6);

  return 0;
}
