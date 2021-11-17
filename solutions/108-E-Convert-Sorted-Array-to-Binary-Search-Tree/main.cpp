#include <iostream>
#include <vector>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-binary-tree.cpp"

TreeNode* sortedArrayToBSTHelper(std::vector<int>& nums, int leftIndex, int rightIndex) {
  if (leftIndex >= rightIndex) {
    return nullptr;
  }
  int mid = (leftIndex + rightIndex) / 2;
  TreeNode* newNode = new TreeNode(nums[mid]);
  newNode->left = sortedArrayToBSTHelper(nums, leftIndex, mid);
  newNode->right = sortedArrayToBSTHelper(nums, mid + 1, rightIndex);
  return newNode;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
  TreeNode* t = sortedArrayToBSTHelper(nums, 0, nums.size());
  std::cout << t->val << "\n";
  return t;
}

int main() {
  std::vector<int> v1 { -10, -3, 0, 5, 9 };
  TreeNode* r1 = sortedArrayToBST(v1);
  printBinaryTree(r1);
  std::cout << std::endl;

  return 0;
}
