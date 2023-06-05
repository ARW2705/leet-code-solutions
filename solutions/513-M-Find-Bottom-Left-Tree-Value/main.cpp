#include <iostream>
#include <queue>
#include <vector>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-success.cpp"

using namespace std;

int findBottomLeftValue(TreeNode* root) {
  queue<TreeNode*> q;
  q.push(root);
  int rowCount = 1, nextRowCount = 0;
  vector<int> row;
  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    row.push_back(node->val);

    if (node->left) {
      ++nextRowCount;
      q.push(node->left);
    }
    if (node->right) {
      ++nextRowCount;
      q.push(node->right);
    }

    --rowCount;
    if (rowCount == 0) {
      row.clear();
      rowCount = nextRowCount;
      nextRowCount = 0;
    }
  }

  return row[0];
}

int main() {
  TreeNode* ta3 = new TreeNode(3);
  TreeNode* ta1 = new TreeNode(1);
  TreeNode* ta2 = new TreeNode(2, ta1, ta3);
  printSuccess(findBottomLeftValue(ta2) == 1);

  TreeNode* tb7 = new TreeNode(7);
  TreeNode* tb5 = new TreeNode(5, tb7, nullptr);
  TreeNode* tb6 = new TreeNode(6);
  TreeNode* tb3 = new TreeNode(3, tb5, tb6);
  TreeNode* tb4 = new TreeNode(4);
  TreeNode* tb2 = new TreeNode(2, tb4, nullptr);
  TreeNode* tb1 = new TreeNode(1, tb2, tb3);
  printSuccess(findBottomLeftValue(tb1) == 7);

  return 0;
}
