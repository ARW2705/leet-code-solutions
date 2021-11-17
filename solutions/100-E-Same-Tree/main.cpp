#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (p == nullptr && q == nullptr) {
    return true;
  } else if (p == nullptr || q == nullptr) {
    return false;
  } else {
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
}

int main() {
  TreeNode* p3 = new TreeNode(3);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p1 = new TreeNode(1, p2, p3);
  TreeNode* q3 = new TreeNode(3);
  TreeNode* q2 = new TreeNode(2);
  TreeNode* q1 = new TreeNode(1, q2, q3);
  printSuccess(isSameTree(p1, q1));

  TreeNode* pa2 = new TreeNode(2);
  TreeNode* pa1 = new TreeNode(1, pa2, nullptr);
  TreeNode* qa2 = new TreeNode(2);
  TreeNode* qa1 = new TreeNode(1, nullptr, qa2);
  printSuccess(!isSameTree(pa1, qa1));

  TreeNode* pb1 = new TreeNode(1);
  TreeNode* pb2 = new TreeNode(2);
  TreeNode* pb1a = new TreeNode(1, pb2, pb1);
  TreeNode* qb2 = new TreeNode(2);
  TreeNode* qb1 = new TreeNode(1);
  TreeNode* qb1a = new TreeNode(1, qb1, qb2);
  printSuccess(!isSameTree(pb1a, qb1a));

  return 0;
}
