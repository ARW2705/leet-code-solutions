#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

bool isUnivalTree(TreeNode* root) {
  if (!root) return true;
  if (!isUnivalTree(root->left) || !isUnivalTree(root->right)) return false;

  TreeNode* leftNode = root->left ? root->left : root;
  TreeNode* rightNode = root->right ? root->right : root;
  return leftNode->val == rightNode->val;
}

int main() {
  TreeNode* a6 = new TreeNode(1);
  TreeNode* a5 = new TreeNode(1);
  TreeNode* a4 = new TreeNode(1);
  TreeNode* a3 = new TreeNode(1, nullptr, a6);
  TreeNode* a2 = new TreeNode(1, a4, a5);
  TreeNode* a1 = new TreeNode(1, a2, a3);
  printSuccess(isUnivalTree(a1));

  TreeNode* b5 = new TreeNode(5);
  TreeNode* b4 = new TreeNode(2);
  TreeNode* b3 = new TreeNode(2, b5, b4);
  TreeNode* b2 = new TreeNode(2);
  TreeNode* b1 = new TreeNode(2, b3, b2);
  printSuccess(!isUnivalTree(b1));

  return 0;
}
