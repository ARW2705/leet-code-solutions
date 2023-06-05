#include <iostream>
#include <vector>
#include <limits>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"

TreeNode* bstFromPreorderHelper(std::vector<int>& preorder, int& rootIndex, int rightBound) {
  if (rootIndex >= preorder.size() || preorder[rootIndex] > rightBound) return nullptr;

  int value = preorder[rootIndex];
  TreeNode* root = new TreeNode(value);
  ++rootIndex;
  root->left = bstFromPreorderHelper(preorder, rootIndex, value);
  root->right = bstFromPreorderHelper(preorder, rootIndex, rightBound);
  return root;
}

TreeNode* bstFromPreorder(std::vector<int>& preorder) {
  int rootIndex = 0;
  return bstFromPreorderHelper(preorder, rootIndex, std::numeric_limits<int>::max());
}

int main() {
  std::vector<int> p1 { 8, 5, 1, 7, 10, 12 };
  TreeNode* t1 = bstFromPreorder(p1);
  std::cout << t1->val << "\n";
  printBinaryTree(t1);

  std::cout << "\n";

  std::vector<int> p2 { 1, 3 };
  TreeNode* t2 = bstFromPreorder(p2);
  printBinaryTree(t2);

  std::cout << std::endl;

  return 0;
}
