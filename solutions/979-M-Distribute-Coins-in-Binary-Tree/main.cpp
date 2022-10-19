#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

int distributeCoinsHelper(TreeNode* root, int& moves) {
  if (!root) return 0;

  int left = distributeCoinsHelper(root->left, moves);
  int right = distributeCoinsHelper(root->right, moves);
  int diff = root->val - 1 + left + right;
  root->val = 1;
  moves += std::abs(diff);
  return diff;
}

int distributeCoins(TreeNode* root) {
  int moves = 0;
  distributeCoinsHelper(root, moves);
  return moves;
}

int main() {
  TreeNode* t1c = new TreeNode(0);
  TreeNode* t1b = new TreeNode(0);
  TreeNode* t1a = new TreeNode(3, t1b, t1c);
  int r1 = distributeCoins(t1a);
  printSuccess(r1 == 2);

  TreeNode* t2c = new TreeNode(0);
  TreeNode* t2b = new TreeNode(3);
  TreeNode* t2a = new TreeNode(0, t2b, t2c);
  int r2 = distributeCoins(t2a);
  printSuccess(r2 == 3);

  TreeNode* t3d = new TreeNode(0);
  TreeNode* t3c = new TreeNode(1, t3d, nullptr);
  TreeNode* t3b = new TreeNode(2);
  TreeNode* t3a = new TreeNode(1, t3b, t3c);
  int r3 = distributeCoins(t3a);
  printSuccess(r3 == 3);

  return 0;
}
