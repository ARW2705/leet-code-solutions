#include <iostream>
#include <queue>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

// bool isSymmetricHelper(TreeNode* lPtr, TreeNode* rPtr) {
//   if (lPtr == nullptr && rPtr == nullptr) {
//     return true;
//   } else if (lPtr == nullptr || rPtr == nullptr) {
//     return false;
//   } else {
//     return (lPtr->val == rPtr->val) && isSymmetricHelper(lPtr->left, rPtr->right) && isSymmetricHelper(lPtr->right, rPtr->left);
//   }
// }
//
// bool isSymmetric(TreeNode* root) {
//   TreeNode* lPtr = root;
//   TreeNode* rPtr = root;
//   return isSymmetricHelper(lPtr, rPtr);
// }

bool isSymmetric(TreeNode* root) {
  std::queue<TreeNode*> q;
  q.push(root->left);
  q.push(root->right);

  while (!q.empty()) {
    TreeNode* left = q.front();
    q.pop();
    TreeNode* right = q.front();
    q.pop();
    if (left != nullptr && right != nullptr) {
      if (left->val != right->val) {
        return false;
      }
      q.push(left->left);
      q.push(right->right);
      q.push(left->right);
      q.push(right->left);
    } else if (left != nullptr || right != nullptr) {
      return false;
    }
  }
  return true;
}

int main() {
  TreeNode* t4a = new TreeNode(4);
  TreeNode* t4b = new TreeNode(4);
  TreeNode* t3a = new TreeNode(3);
  TreeNode* t3b = new TreeNode(3);
  TreeNode* t2a = new TreeNode(2, t3a, t4a);
  TreeNode* t2b = new TreeNode(2, t4b, t3b);
  TreeNode* t1 = new TreeNode(1, t2a, t2b);
  printSuccess(isSymmetric(t1));

  TreeNode* t3l = new TreeNode(3);
  TreeNode* t3r = new TreeNode(3);
  TreeNode* t2l = new TreeNode(2, nullptr, t3l);
  TreeNode* t2r = new TreeNode(2, nullptr, t3r);
  TreeNode* t1c = new TreeNode(1, t2l, t2r);
  printSuccess(!isSymmetric(t1c));
  return 0;
}
