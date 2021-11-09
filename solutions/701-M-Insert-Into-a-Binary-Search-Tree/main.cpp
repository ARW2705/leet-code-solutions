#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"

void insertIntoBSTHelper(TreeNode*& node, int val) {
  if (node == nullptr) {
    node = new TreeNode(val);
  } else if (node->val > val) {
      insertIntoBSTHelper(node->left, val);
  } else {
    insertIntoBSTHelper(node->right, val);
  }
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
  insertIntoBSTHelper(root, val);
  return root;
}

int main() {
  TreeNode* t1 = new TreeNode(1);
  TreeNode* t3 = new TreeNode(3);
  TreeNode* t2 = new TreeNode(2, t1, t3);
  TreeNode* t7 = new TreeNode(7);
  TreeNode* t4 = new TreeNode(4, t2, t7);
  printBinaryTree(t4);
  std::cout << "\n";
  printBinaryTree(insertIntoBST(t4, 5));

  return 0;
}
