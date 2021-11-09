#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"
#include "../../utilities/print-success.cpp"

bool hasPathSumHelper(TreeNode* node, int& targetSum, int currentSum) {
  if (node == nullptr) {
    return false;
  } else {
    int newSum = currentSum + node->val;
    bool foundLeft = hasPathSumHelper(node->left, targetSum, newSum);
    if (foundLeft) {
      return foundLeft;
    }
    bool foundRight = hasPathSumHelper(node->right, targetSum, newSum);
    if (foundRight) {
      return foundRight;
    }
    return node->left == nullptr && node->right == nullptr && targetSum == newSum;
  }
}

bool hasPathSum(TreeNode* root, int targetSum) {
  return hasPathSumHelper(root, targetSum, 0);
}

int main() {
  TreeNode* t1 = new TreeNode(1);
  TreeNode* t2 = new TreeNode(2);
  TreeNode* t7 = new TreeNode(7);
  TreeNode* t4a = new TreeNode(4, nullptr, t1);
  TreeNode* t13 = new TreeNode(13);
  TreeNode* t11 = new TreeNode(11, t7, t2);
  TreeNode* t8 = new TreeNode(8, t13, t4a);
  TreeNode* t4b = new TreeNode(4, t11, nullptr);
  TreeNode* t5 = new TreeNode(5, t4b, t8);
  printSuccess(hasPathSum(t5, 22));

  TreeNode* t23 = new TreeNode(3);
  TreeNode* t22 = new TreeNode(2);
  TreeNode* t21 = new TreeNode(1, t22, t23);
  printSuccess(!hasPathSum(t21, 5));

  TreeNode* t32 = new TreeNode(2);
  TreeNode* t31 = new TreeNode(1, t32, nullptr);
  printSuccess(!hasPathSum(t31, 0));

  TreeNode* t42 = new TreeNode(2);
  TreeNode* t41 = new TreeNode(1, t42, nullptr);
  printSuccess(!hasPathSum(t41, 1));

  return 0;
}
