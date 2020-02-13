#include <iostream>

#include "binary-tree.hpp"

void printInOrderTraversal(TreeNode* node) {
  if (node == nullptr) {
    return;
  }
  std::cout << node->val << " ";
  printInOrderTraversal(node->left);
  printInOrderTraversal(node->right);
}

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

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
  if (t1 == nullptr && t2 == nullptr) {
    return nullptr;
  }

  int sum = 0;
  if (t1 != nullptr) sum += t1->val;
  if (t2 != nullptr) sum += t2->val;
  TreeNode* newNode = new TreeNode(sum);

  newNode->left = mergeTrees(t1 ? t1->left: t1, t2 ? t2->left: t2);
  newNode->right = mergeTrees(t1 ? t1->right: t1, t2 ? t2->right: t2);
  return newNode;
}

int main() {
  TreeNode* t1 = new TreeNode(1);
  t1->left = new TreeNode(3);
  t1->left->left = new TreeNode(5);
  t1->right = new TreeNode(2);

  TreeNode* t2 = new TreeNode(2);
  t2->left = new TreeNode(1);
  t2->left->right = new TreeNode(4);
  t2->right = new TreeNode(3);
  t2->right->right = new TreeNode(7);

  TreeNode* expected = new TreeNode(3);
  expected->left = new TreeNode(4);
  expected->left->left = new TreeNode(5);
  expected->left->right = new TreeNode(4);
  expected->right = new TreeNode(5);
  expected->right->right = new TreeNode(7);

  TreeNode* result = mergeTrees(t1, t2);

  bool passed = compareTrees(expected, result);

  printInOrderTraversal(expected);
  std::cout << "\n";
  printInOrderTraversal(result);
  std::cout << "\n";

  std::cout << (passed ? "PASS": "FAIL") << "\n";

  return 0;
}
