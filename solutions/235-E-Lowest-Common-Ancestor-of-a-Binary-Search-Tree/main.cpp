#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root->val > p->val && root->val > q->val) {
    return lowestCommonAncestor(root->left, p, q);
  } else if (root->val < p->val && root->val < q->val) {
    return lowestCommonAncestor(root->right, p, q);
  }
  return root;
}

int main() {
  TreeNode* t5a = new TreeNode(5);
  TreeNode* t3a = new TreeNode(3);
  TreeNode* t9a = new TreeNode(9);
  TreeNode* t7a = new TreeNode(7);
  TreeNode* t4a = new TreeNode(4, t3a, t5a);
  TreeNode* t0a = new TreeNode(0);
  TreeNode* t8a = new TreeNode(8, t7a, t9a);
  TreeNode* t2a = new TreeNode(2, t0a, t4a);
  TreeNode* t6a = new TreeNode(6, t2a, t8a);
  TreeNode* r1 = lowestCommonAncestor(t6a, t2a, t8a);
  printSuccess(r1->val == 6);
  TreeNode* r2 = lowestCommonAncestor(t6a, t2a, t4a);
  printSuccess(r2->val == 2);
  printSuccess(lowestCommonAncestor(t6a, t9a, t0a)->val == 6);

  TreeNode* t3b = new TreeNode(3);
  TreeNode* t2b = new TreeNode(2, nullptr, t3b);
  TreeNode* r3 = lowestCommonAncestor(t2b, t3b, t2b);
  printSuccess(r3->val == 2);

  return 0;
}
