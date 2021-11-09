#include <iostream>
#include <vector>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

void isValidBSTHelper(TreeNode* node, std::vector<int>& traversal) {
  if (node != nullptr) {
    isValidBSTHelper(node->left, traversal);
    traversal.push_back(node->val);
    isValidBSTHelper(node->right, traversal);
  }
}

bool isValidBST(TreeNode* root) {
  std::vector<int> traversal;
  isValidBSTHelper(root, traversal);
  for (int i = 0; i < traversal.size() - 1; ++i) {
    if (traversal[i] >= traversal[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  TreeNode* t3a = new TreeNode(3);
  TreeNode* t1a = new TreeNode(1);
  TreeNode* t2a = new TreeNode(2, t1a, t3a);
  printSuccess(isValidBST(t2a));

  TreeNode* t6b = new TreeNode(6);
  TreeNode* t3b = new TreeNode(3);
  TreeNode* t4b = new TreeNode(4, t3b, t6b);
  TreeNode* t1b = new TreeNode(1);
  TreeNode* t5b = new TreeNode(5, t1b, t4b);
  printSuccess(!isValidBST(t5b));

  return 0;
}
