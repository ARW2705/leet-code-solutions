#include <iostream>
#include <vector>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"
#include "../../utilities/print-vector.cpp"

using namespace std;

void setValues(TreeNode* root, vector<int>& values) {
  if (root == nullptr) return;

  setValues(root->left, values);
  values.push_back(root->val);
  setValues(root->right, values);
}

TreeNode* buildBalancedBST(vector<int>& values, int start, int end) {
  if (start > end) return nullptr;

  int mid = ((end - start) / 2) + start;
  TreeNode* newNode = new TreeNode(values[mid]);
  newNode->left = buildBalancedBST(values, start, mid - 1);
  newNode->right = buildBalancedBST(values, mid + 1, end);

  return newNode;
}

TreeNode* balanceBST(TreeNode* root) {
  vector<int> values;
  setValues(root, values);
  return buildBalancedBST(values, 0, values.size() - 1);
}

int main() {
  TreeNode* a4 = new TreeNode(4);
  TreeNode* a3 = new TreeNode(3, nullptr, a4);
  TreeNode* a2 = new TreeNode(2, nullptr, a3);
  TreeNode* a1 = new TreeNode(1, nullptr, a2);
  TreeNode* r1 = balanceBST(a1);
  printBinaryTree(r1);
  cout << endl;
  return 0;
}
