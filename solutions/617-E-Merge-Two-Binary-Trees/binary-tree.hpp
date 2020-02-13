#ifndef _binary_tree_hpp
#define _binary_tree_hpp

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

#endif
