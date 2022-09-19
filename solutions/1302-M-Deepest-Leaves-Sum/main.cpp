#include <iostream>
#include <vector>
#include <limits>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

bool deepestLeavesSumHelper(TreeNode* node, int depth, int& maxDepth, int& sum) {
  if (!node) return true;

  bool left = deepestLeavesSumHelper(node->left, depth + 1, maxDepth, sum);
  bool right = deepestLeavesSumHelper(node->right, depth + 1, maxDepth, sum);

  if (left && right) {
    if (depth > maxDepth) {
      maxDepth = depth;
      sum = node->val;
    } else if (depth == maxDepth) {
      sum += node->val;
    }
  }

  return false;
}

int deepestLeavesSum(TreeNode* root) {
  int maxDepth = 0;
  int sum = 0;
  deepestLeavesSumHelper(root, 0, maxDepth, sum);
  return sum;
}

int main() {
  TreeNode* n8 = new TreeNode(8);
  TreeNode* n6 = new TreeNode(6, nullptr, n8);
  TreeNode* n3 = new TreeNode(3, nullptr, n6);
  TreeNode* n7 = new TreeNode(7);
  TreeNode* n4 = new TreeNode(4, n7, nullptr);
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n2 = new TreeNode(2, n4, n5);
  TreeNode* n1 = new TreeNode(1, n2, n3);
  int r1 = deepestLeavesSum(n1);
  std::cout << (r1 == 15 ? "PASS" : "FAIL") << "\n";

  return 0;
}
