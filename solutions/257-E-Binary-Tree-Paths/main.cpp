#include <iostream>
#include <vector>
#include <string>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-vector.cpp"

void binaryTreePathsHelper(TreeNode* node, std::vector<std::string>& paths, std::string path) {
  if (node) {
    path += std::to_string(node->val);
    if (!node->left && !node->right) {
      paths.push_back(path);
    } else {
      path += "->";
      binaryTreePathsHelper(node->left, paths, path);
      binaryTreePathsHelper(node->right, paths, path);
    }
  }
}

std::vector<std::string> binaryTreePaths(TreeNode* root) {
  std::vector<std::string> paths;
  std::string path = "";
  binaryTreePathsHelper(root, paths, path);
  return paths;
}

int main() {
  TreeNode* a5 = new TreeNode(5);
  TreeNode* a3 = new TreeNode(3);
  TreeNode* a2 = new TreeNode(2, nullptr, a5);
  TreeNode* a1 = new TreeNode(1, a2, a3);
  std::vector<std::string> r1 = binaryTreePaths(a1);
  printVector(r1);

  TreeNode* b1 = new TreeNode(1);
  std::vector<std::string> r2 = binaryTreePaths(b1);
  printVector(r2);

  return 0;
}
