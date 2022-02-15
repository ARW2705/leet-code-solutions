#include <iostream>
#include <vector>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

void findCommonRoots(TreeNode* node, int target, std::vector<TreeNode*>& commonRoots) {
  if (node) {
    if (node->val == target) {
      commonRoots.push_back(node);
    }
    findCommonRoots(node->left, target, commonRoots);
    findCommonRoots(node->right, target, commonRoots);
  }
}

bool isIdenticalTree(TreeNode* root, TreeNode* subRoot) {
  if ((root && !subRoot) || (!root && subRoot) || (root && subRoot && root->val != subRoot->val)) {
    return false;
  } else if (!root && !subRoot) {
    return true;
  }
  bool isMatch = isIdenticalTree(root->left, subRoot->left);
  if (!isMatch) {
    return false;
  }
  return isIdenticalTree(root->right, subRoot->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  std::vector<TreeNode*> commonRoots;
  findCommonRoots(root, subRoot->val, commonRoots);
  for (TreeNode* commonRoot : commonRoots) {
    if (isIdenticalTree(commonRoot, subRoot)) {
      return true;
    }
  }
  return false;
}

int main() {
  TreeNode* a2 = new TreeNode(2);
  TreeNode* a1 = new TreeNode(1);
  TreeNode* a4 = new TreeNode(4, a1, a2);
  TreeNode* a5 = new TreeNode(5);
  TreeNode* a3 = new TreeNode(3, a4, a5);

  TreeNode* aa2 = new TreeNode(2);
  TreeNode* aa1 = new TreeNode(1);
  TreeNode* aa4 = new TreeNode(4, aa1, aa2);

  printSuccess(isSubtree(a3, aa4));


  TreeNode* b0 = new TreeNode(0);
  TreeNode* b2 = new TreeNode(2, b0, nullptr);
  TreeNode* b1 = new TreeNode(1);
  TreeNode* b4 = new TreeNode(4, b1, b2);
  TreeNode* b5 = new TreeNode(5);
  TreeNode* b3 = new TreeNode(3, b4, b5);

  TreeNode* bb2 = new TreeNode(2);
  TreeNode* bb1 = new TreeNode(1);
  TreeNode* bb4 = new TreeNode(4, bb1, bb2);

  printSuccess(!isSubtree(b3, bb4));


  TreeNode* c2 = new TreeNode(2);
  TreeNode* c1 = new TreeNode(1);
  TreeNode* c4 = new TreeNode(6, c1, c2);
  TreeNode* c5 = new TreeNode(5);
  TreeNode* c3 = new TreeNode(3, c4, c5);

  TreeNode* cc2 = new TreeNode(2);
  TreeNode* cc1 = new TreeNode(1);
  TreeNode* cc4 = new TreeNode(4, cc1, cc2);

  printSuccess(!isSubtree(c3, cc4));


  TreeNode* d1 = new TreeNode(1);
  TreeNode* d11 = new TreeNode(1, d1, nullptr);

  TreeNode* dd1 = new TreeNode(1);

  printSuccess(isSubtree(d11, dd1));

  return 0;
}
