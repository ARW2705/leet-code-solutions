#include <iostream>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

int findNodeDepth(TreeNode* node, int target, int& parent) {
  if (!node) {
    return 0;
  } else if (node->val == target) {
    return 1;
  } else {
    int depth = findNodeDepth(node->left, target, parent);
    if (!depth) {
      depth = findNodeDepth(node->right, target, parent);
    }

    if (depth) {
      if (depth == 1) {
        parent = node->val;
      }
      return depth + 1;
    }
    return 0;
  }
}

bool isCousins(TreeNode* root, int x, int y) {
  int xParent;
  int xDepth = findNodeDepth(root, x, xParent);

  int yParent;
  int yDepth = findNodeDepth(root, y, yParent);

  return xParent != yParent && xDepth == yDepth;
}

int main() {
  TreeNode* a4 = new TreeNode(4);
  TreeNode* a3 = new TreeNode(3);
  TreeNode* a2 = new TreeNode(2, a4, nullptr);
  TreeNode* a1 = new TreeNode(1, a2, a3);
  printSuccess(!isCousins(a1, 4, 3));

  TreeNode* b5 = new TreeNode(5);
  TreeNode* b4 = new TreeNode(4);
  TreeNode* b3 = new TreeNode(3, nullptr, b5);
  TreeNode* b2 = new TreeNode(2, nullptr, b4);
  TreeNode* b1 = new TreeNode(1, b2, b3);
  printSuccess(isCousins(b1, 5, 4));

  TreeNode* c4 = new TreeNode(4);
  TreeNode* c3 = new TreeNode(3);
  TreeNode* c2 = new TreeNode(2, nullptr, c4);
  TreeNode* c1 = new TreeNode(1, c2, c3);
  printSuccess(!isCousins(c1, 4, 3));

  return 0;
}
