#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

// void sumOfLeftLeavesHelper(TreeNode* node, bool isLeft, int& sum) {
//   if (node != nullptr) {
//     sumOfLeftLeavesHelper(node->left, true, sum);
//     if (isLeft && node->left == nullptr && node->right == nullptr) {
//       sum += node->val;
//     }
//     sumOfLeftLeavesHelper(node->right, false, sum);
//   }
// }
//
// int sumOfLeftLeaves(TreeNode* root) {
//   int sum = 0;
//   sumOfLeftLeavesHelper(root, false, sum);
//   return sum;
// }

void sumOfLeftLeavesHelper(TreeNode* node, int& sum) {
  if (!node) return;
  if (node->left && !node->left->left && !node->left->right) {
    sum += node->left->val;
  }
  sumOfLeftLeavesHelper(node->left, sum);
  sumOfLeftLeavesHelper(node->right, sum);
}

int sumOfLeftLeaves(TreeNode* root) {
  int sum = 0;
  sumOfLeftLeavesHelper(root, sum);
  return sum;
}

int main() {
  TreeNode* t7 = new TreeNode(7);
  TreeNode* t15 = new TreeNode(15);
  TreeNode* t20 = new TreeNode(20, t15, t7);
  TreeNode* t9 = new TreeNode(9);
  TreeNode* t3 = new TreeNode(3, t9, t20);
  std::cout << sumOfLeftLeaves(t3) << "\n";
  printSuccess(sumOfLeftLeaves(t3) == 24);

  TreeNode* t1 = new TreeNode(1);
  printSuccess(sumOfLeftLeaves(t1) == 0);

  return 0;
}
