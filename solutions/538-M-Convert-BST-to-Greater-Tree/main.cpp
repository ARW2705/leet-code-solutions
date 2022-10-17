#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"

void convertBSTHelper(TreeNode* root, int& sumSoFar) {
  if (!root) return;

  convertBSTHelper(root->right, sumSoFar);
  root->val += sumSoFar;
  sumSoFar = root->val;
  convertBSTHelper(root->left, sumSoFar);
}

TreeNode* convertBST(TreeNode* root) {
  int sumSoFar = 0;
  convertBSTHelper(root, sumSoFar);
  return root;
}

int main() {
  TreeNode* n8 = new TreeNode(8);
  TreeNode* n7 = new TreeNode(7, nullptr, n8);
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n6 = new TreeNode(6, n5, n7);
  TreeNode* n3 = new TreeNode(3);
  TreeNode* n2 = new TreeNode(2, nullptr, n3);
  TreeNode* n0 = new TreeNode(0);
  TreeNode* n1 = new TreeNode(1, n0, n2);
  TreeNode* n4 = new TreeNode(4, n1, n6);
  TreeNode* r1 = convertBST(n4);
  printBinaryTree(r1);

  return 0;
}
