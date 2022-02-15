#include <iostream>
#include <vector>
#include <queue>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-vector.cpp"

std::vector<double> averageOfLevels(TreeNode* root) {
  std::queue<TreeNode*> q;
  q.push(root);

  std::vector<double> averages;
  int currentLevelRemaining = 1;
  int nextLevelCount = 0;
  double currentSum = 0;
  int currentCount = 1;
  while(!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    --currentLevelRemaining;
    currentSum += node->val;

    if (node->left) {
      ++nextLevelCount;
      q.push(node->left);
    }
    if (node->right) {
      ++nextLevelCount;
      q.push(node->right);
    }

    if (!currentLevelRemaining) {
      averages.push_back(currentSum / currentCount);
      currentSum = 0;
      currentCount = nextLevelCount;
      currentLevelRemaining = nextLevelCount;
      nextLevelCount = 0;
    }
  }

  return averages;
}

int main() {
  TreeNode* a7 = new TreeNode(7);
  TreeNode* a15 = new TreeNode(15);
  TreeNode* a20 = new TreeNode(20, a15, a7);
  TreeNode* a9 = new TreeNode(9);
  TreeNode* a3 = new TreeNode(3, a9, a20);

  std::vector<double> r1 = averageOfLevels(a3);
  printVector(r1);

  TreeNode* b7 = new TreeNode(7);
  TreeNode* b15 = new TreeNode(15);
  TreeNode* b9 = new TreeNode(9, b15, b7);
  TreeNode* b20 = new TreeNode(20);
  TreeNode* b3 = new TreeNode(3, b9, b20);

  std::vector<double> r2 = averageOfLevels(b3);
  printVector(r2);

  return 0;
}
