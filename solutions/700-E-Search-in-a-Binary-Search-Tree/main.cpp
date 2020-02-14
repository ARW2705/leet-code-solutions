#include <iostream>

#include "binary-tree.hpp"

bool compareTrees(TreeNode* expected, TreeNode* given) {
  if (expected == nullptr && given == nullptr) {
    return true;
  }
  if ((expected == nullptr && given != nullptr) || (expected != nullptr && given == nullptr)) {
    return false;
  }
  if (expected->val != given->val) {
    return false;
  }
  return (compareTrees(expected->left, given->left)
          && compareTrees(expected->right, given->right));
}

TreeNode* searchBST(TreeNode* root, int val) {
  if (root == nullptr) {
    return root;
  }
  if (val < root->val) {
    return searchBST(root->left, val);
  } else if (val > root->val) {
    return searchBST(root->right, val);
  } else {
    return root;
  }
}

int main() {
  TreeNode* testRoot = new TreeNode(4);
  testRoot->left = new TreeNode(2);
  testRoot->left->left = new TreeNode(1);
  testRoot->left->right = new TreeNode(3);
  testRoot->right = new TreeNode(7);

  TreeNode* search2 = searchBST(testRoot, 2);
  TreeNode* expected2 = testRoot->left;
  bool search2Equal = compareTrees(expected2, search2);
  std::cout << (search2Equal ? "PASS": "FAIL") << "\n";

  TreeNode* search5 = searchBST(testRoot, 5);
  TreeNode* expected5 = nullptr;
  bool search5Equal = compareTrees(expected5, search5);
  std::cout << (search5Equal ? "PASS": "FAIL") << "\n";
  return 0;
}
