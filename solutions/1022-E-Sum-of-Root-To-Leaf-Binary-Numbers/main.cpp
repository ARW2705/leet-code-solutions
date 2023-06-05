#include <iostream>
#include <vector>
#include <string>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

using namespace std;

bool sumRootToLeafHelper(TreeNode* root, int& sum, string& path) {
  if (root == nullptr) return false;

  path += to_string(root->val);
  bool left = sumRootToLeafHelper(root->left, sum, path);
  bool right = sumRootToLeafHelper(root->right, sum, path);
  if (!left && !right) {
    sum += stoi(path, nullptr, 2);
  }
  path.pop_back();
  return true;
}

int sumRootToLeaf(TreeNode* root) {
  string path = "";
  int sum = 0;
  sumRootToLeafHelper(root, sum, path);
  return sum;
}

int main() {
  TreeNode* t7 = new TreeNode(1);
  TreeNode* t6 = new TreeNode(0);
  TreeNode* t3 = new TreeNode(1, t6, t7);
  TreeNode* t5 = new TreeNode(1);
  TreeNode* t4 = new TreeNode(0);
  TreeNode* t2 = new TreeNode(0, t4, t5);
  TreeNode* t1 = new TreeNode(1, t2, t3);
  printSuccess(sumRootToLeaf(t1) == 22);

  printSuccess(sumRootToLeaf(new TreeNode(0)) == 0);

  return 0;
}
