#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"

TreeNode* newRoot = nullptr;
TreeNode* prevNode = nullptr;

void increasingBSTHelper(TreeNode* node) {
  if (!node) return;

  increasingBSTHelper(node->left);
  if (!newRoot) {
    newRoot = node;
    prevNode = newRoot;
  } else {
    node->left = nullptr;
    prevNode->right = node;
    prevNode = prevNode->right;
  }
  increasingBSTHelper(node->right);
}

TreeNode* increasingBST(TreeNode* root) {
  increasingBSTHelper(root);
  return newRoot;
}

int main() {
  TreeNode* n9 = new TreeNode(9);
  TreeNode* n7 = new TreeNode(7);
  TreeNode* n8 = new TreeNode(8, n7, n9);
  TreeNode* n6 = new TreeNode(6, nullptr, n8);
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2, n1, nullptr);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n3 = new TreeNode(3, n2, n4);
  TreeNode* n5 = new TreeNode(5, n3, n6);
  TreeNode* r1 = increasingBST(n5);
  printBinaryTree(r1);

  return 0;
}
