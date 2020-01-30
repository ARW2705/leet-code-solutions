#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int _val) {
    val = _val;
    left = nullptr;
    right = nullptr;
  }
};

void printResult(int exampleNum, int result, int lvalue, int rvalue, int expected) {
  std::cout
    << "For example "
    << exampleNum
    << ", the sum of tree values between "
    << lvalue
    << " and "
    << rvalue
    << " should be "
    << expected
    << ", got "
    << result
    << "\n"
    << (expected == result ? "PASS": "FAIL")
    << "\n";
}

void addNodeToBST(TreeNode*& node, int value) {
  if (node == nullptr) {
    node = new TreeNode(value);
  } else if (node->val < value) {
    addNodeToBST(node->right, value);
  } else {
    addNodeToBST(node->left, value);
  }
}

TreeNode* buildTree(std::vector<int>& nodes) {
  TreeNode* root = new TreeNode(nodes[0]);
  for (int i=1; i < nodes.size(); ++i) {
    addNodeToBST(root, nodes[i]);
  }
  return root;
}

int rangeSumBST(TreeNode* root, int L, int R) {
    int leftSum = 0;
    int rightSum = 0;
    if (root == nullptr) {
        return 0;
    }
    if (root->val >= L) {
        leftSum = rangeSumBST(root->left, L, R);
    }
    if (root->val <= R) {
        rightSum = rangeSumBST(root->right, L, R);
    }
    return leftSum + rightSum + ((root->val >= L && root->val <= R) ? root->val: 0);
}

int main() {
  std::vector<int> ex1Nodes { 10, 5, 15, 3, 7, 18 };
  TreeNode* ex1 = buildTree(ex1Nodes);
  int l1 = 7;
  int r1 = 15;
  printResult(1, rangeSumBST(ex1, l1, r1), l1, r1, 32);

  std::vector<int> ex2Nodes { 10, 5, 15, 3, 7, 13, 18, 1, 6 };
  TreeNode* ex2 = buildTree(ex2Nodes);
  int l2 = 6;
  int r2 = 10;
  printResult(2, rangeSumBST(ex2, l2, r2), l2, r2, 23);
  return 0;
}
