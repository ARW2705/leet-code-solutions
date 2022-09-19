#include <iostream>
#include <vector>
#include <algorithm>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"

bool delNodesHelper(TreeNode* node, std::vector<int>& to_delete, bool isRoot, std::vector<TreeNode*>& roots) {
  if (node) {
    if (std::find(to_delete.begin(), to_delete.end(), node->val) != to_delete.end()) {
      delNodesHelper(node->left, to_delete, true, roots);
      delNodesHelper(node->right, to_delete, true, roots);
      delete node;
      return true;
    } else {
      if (isRoot) roots.push_back(node);

      bool deletedLeft = delNodesHelper(node->left, to_delete, false, roots);
      if (deletedLeft) node->left = nullptr;
      
      bool deletedRight = delNodesHelper(node->right, to_delete, false, roots);
      if (deletedRight) node->right = nullptr;
    }
  }
  return false;
}

std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {
  std::vector<TreeNode*> roots;
  delNodesHelper(root, to_delete, true, roots);
  return roots;
}

int main() {
  TreeNode* n7 = new TreeNode(7);
  TreeNode* n6 = new TreeNode(6);
  TreeNode* n3 = new TreeNode(3, n6, n7);
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n2 = new TreeNode(2, n4, n5);
  TreeNode* n1 = new TreeNode(1, n2, n3);
  std::vector<int> d1 { 3, 5 };
  std::vector<TreeNode*> r1 = delNodes(n1, d1);
  for (auto n : r1) {
    printBinaryTree(n);
    std::cout << "\n";
  }

  return 0;
}
