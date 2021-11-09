#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"

TreeNode* invertTree(TreeNode* root) {
  if (root != nullptr) {
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
  }
  return root;
}

int main() {
  TreeNode* t11 = new TreeNode(1);
  TreeNode* t13 = new TreeNode(3);
  TreeNode* t16 = new TreeNode(6);
  TreeNode* t19 = new TreeNode(9);
  TreeNode* t12 = new TreeNode(2, t11, t13);
  TreeNode* t17 = new TreeNode(7, t16, t19);
  TreeNode* t14 = new TreeNode(4, t12, t17);
  printBinaryTree(t14);
  std::cout << "\n";
  printBinaryTree(invertTree(t14));
  std::cout << std::endl;

  return 0;
}
