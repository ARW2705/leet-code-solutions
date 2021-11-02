#include <iostream>
#include <vector>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/compare-vectors.cpp"

void preorderTraversalHelper(TreeNode* node, std::vector<int>& traversal) {
  if (node != nullptr) {
    preorderTraversalHelper(node->left, traversal);
    preorderTraversalHelper(node->right, traversal);
    traversal.push_back(node->val);
  }
}

std::vector<int> preorderTraversal(TreeNode* root) {
  std::vector<int> traversal;
  preorderTraversalHelper(root, traversal);
  return traversal;
}

int main() {
  TreeNode* t3 = new TreeNode(3);
  TreeNode* t2 = new TreeNode(2, t3, nullptr);
  TreeNode* t1 = new TreeNode(1, nullptr, t2);
  std::vector<int> r1 = preorderTraversal(t1);
  std::vector<int> e1 { 3, 2, 1 };
  std::cout << (compareVector(r1, e1) ? "PASS" : "FAIL") << "\n";

  std::vector<int> r2 = preorderTraversal(nullptr);
  std::vector<int> e2 {};
  std::cout << (compareVector(r2, e2) ? "PASS" : "FAIL") << "\n";

  TreeNode* t1b = new TreeNode(1);
  std::vector<int> r3 = preorderTraversal(t1b);
  std::vector<int> e3 { 1 };
  std::cout << (compareVector(r3, e3) ? "PASS" : "FAIL") << "\n";

  TreeNode* t2c = new TreeNode(2);
  TreeNode* t1c = new TreeNode(1, t2c, nullptr);
  std::vector<int> r4 = preorderTraversal(t1c);
  std::vector<int> e4 { 2, 1 };
  std::cout << (compareVector(r4, e4) ? "PASS" : "FAIL") << "\n";

  TreeNode* t2d = new TreeNode(2);
  TreeNode* t1d = new TreeNode(1, nullptr, t2d);
  std::vector<int> r5 = preorderTraversal(t1d);
  std::vector<int> e5 { 2, 1 };
  std::cout << (compareVector(r5, e5) ? "PASS" : "FAIL") << "\n";

  return 0;
}
