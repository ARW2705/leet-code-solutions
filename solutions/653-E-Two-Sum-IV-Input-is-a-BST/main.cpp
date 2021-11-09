#include <iostream>
#include <set>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"
#include "../../utilities/print-success.cpp"

bool findTargetHelper(TreeNode* node, int k, std::set<int>& previousValues) {
  if (node == nullptr) {
    return false;
  } else if (previousValues.find(k - node->val) != previousValues.end()) {
    return true;
  } else {
    previousValues.insert(node->val);
    bool foundLeft = findTargetHelper(node->left, k, previousValues);
    if (foundLeft) {
      return foundLeft;
    }
    bool foundRight = findTargetHelper(node->right, k, previousValues);
    if (foundRight) {
      return foundRight;
    }
    return false;
  }
}

bool findTarget(TreeNode* root, int k) {
  std::set<int> previousValues;
  return findTargetHelper(root, k, previousValues);
}

int main() {
  TreeNode* t7a = new TreeNode(7);
  TreeNode* t4a = new TreeNode(4);
  TreeNode* t2a = new TreeNode(2);
  TreeNode* t6a = new TreeNode(6, nullptr, t7a);
  TreeNode* t3a = new TreeNode(3, t2a, t4a);
  TreeNode* t5a = new TreeNode(5, t3a, t6a);
  printSuccess(findTarget(t5a, 9));
  printSuccess(!findTarget(t5a, 28));

  TreeNode* t3b = new TreeNode(3);
  TreeNode* t1b = new TreeNode(1);
  TreeNode* t2b = new TreeNode(2, t1b, t3b);
  printSuccess(findTarget(t2b, 4));
  printSuccess(!findTarget(t2b, 1));
  printSuccess(findTarget(t2b, 3));

  return 0;
}
