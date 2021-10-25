#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
  if (root1 == nullptr) {
    return root2;
  } else if (root2 == nullptr) {
    return root1;
  } else {
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
  }
}

int main() {
  TreeNode* tr15 = new TreeNode(5);
  TreeNode* tr13 = new TreeNode(3, tr15, nullptr);
  TreeNode* tr12 = new TreeNode(2);
  TreeNode* tr11 = new TreeNode(1, tr13, tr12);

  TreeNode* tr27 = new TreeNode(7);
  TreeNode* tr24 = new TreeNode(4);
  TreeNode* tr23 = new TreeNode(3, nullptr, tr24);
  TreeNode* tr21 = new TreeNode(1, nullptr, tr24);
  TreeNode* tr22 = new TreeNode(2, tr21, tr23);

  TreeNode* r1 = mergeTrees(tr11, tr22);
  printBinaryTree(r1);
  std::cout << "\n";

  TreeNode* tr31 = new TreeNode(1);

  TreeNode* tr42 = new TreeNode(2);
  TreeNode* tr41 = new TreeNode(1, nullptr, tr42);

  TreeNode* r2 = mergeTrees(tr31, tr41);
  printBinaryTree(r2);
  std::cout << "\n";
  return 0;
}
