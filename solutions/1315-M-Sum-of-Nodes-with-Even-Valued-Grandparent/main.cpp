#include <iostream>
#include <queue>
#include <tuple>
#include "../../utilities/tree-node.hpp"

int sumEvenGrandparent(TreeNode* root) {
  int sum = 0;
  std::queue<std::tuple<TreeNode*, bool, bool>> q;
  q.push(std::make_tuple(root, false, false));

  while (!q.empty()) {
    std::tuple<TreeNode*, bool, bool> elem = q.front();
    q.pop();
    TreeNode* node = std::get<0>(elem);
    bool isParentEven = std::get<1>(elem);
    bool isGrandparentEven = std::get<2>(elem);

    if (isGrandparentEven) {
      sum += node->val;
    }

    bool isNodeEven = node->val % 2 == 0;
    if (node->left) {
      q.push(std::make_tuple(node->left, isNodeEven, isParentEven));
    }
    if (node->right) {
      q.push(std::make_tuple(node->right, isNodeEven, isParentEven));
    }
  }

  return sum;
}

int main() {
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n3 = new TreeNode(3, nullptr, n5);
  TreeNode* n1a = new TreeNode(1);
  TreeNode* n8 = new TreeNode(8, n1a, n3);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n1b = new TreeNode(1);
  TreeNode* n7a = new TreeNode(7, n1b, n4);
  TreeNode* n9 = new TreeNode(9);
  TreeNode* n2 = new TreeNode(2, n9, nullptr);
  TreeNode* n7b = new TreeNode(7, n2, n7a);
  TreeNode* n6 = new TreeNode(6, n7b, n8);
  int sum = sumEvenGrandparent(n6);
  std::cout << sum << "\n";
  std::cout << (sum == 18 ? "PASS" : "FAIL") << std::endl;

  return 0;
}
