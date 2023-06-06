#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "../../utilities/tree-node.hpp"
#include "../../utilities/print-vector.cpp"
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

using namespace std;

// void populateValuesMap(map<int, int>& values, TreeNode* root) {
//   if (root == nullptr) return;

//   populateValuesMap(values, root->left);
//   ++values[root->val];
//   populateValuesMap(values, root->right);
// }

// vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
//   map<int, int> values;
//   populateValuesMap(values, root1);
//   populateValuesMap(values, root2);
//   vector<int> elems;
//   for (auto iter = values.begin(); iter != values.end(); ++iter) {
//     for (int i = 0; i < iter->second; ++i) {
//       elems.push_back(iter->first);
//     }
//   }
//   return elems;
// }

void getAllElementsHelper(vector<int>& elems, TreeNode* root) {
  if (root == nullptr) return;

  getAllElementsHelper(elems, root->left);
  elems.push_back(root->val);
  getAllElementsHelper(elems, root->right);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
  vector<int> elems;
  getAllElementsHelper(elems, root1);
  getAllElementsHelper(elems, root2);
  sort(elems.begin(), elems.end());
  return elems;
}

int main() {
  TreeNode* r1c = new TreeNode(4);
  TreeNode* r1b = new TreeNode(1);
  TreeNode* r1a = new TreeNode(2, r1b, r1c);
  TreeNode* r1f = new TreeNode(3);
  TreeNode* r1e = new TreeNode(0);
  TreeNode* r1d = new TreeNode(1, r1e, r1f);
  vector<int> e1 { 0, 1, 1, 2, 3, 4 };
  vector<int> r1 = getAllElements(r1a, r1d);
  printVector(r1);
  printSuccess(compareVector(r1, e1));

  TreeNode* r2b = new TreeNode(8);
  TreeNode* r2a = new TreeNode(1, nullptr, r2b);
  TreeNode* r2d = new TreeNode(1);
  TreeNode* r2c = new TreeNode(8, r2d, nullptr);
  vector<int> e2 { 1, 1, 8, 8 };
  vector<int> r2 = getAllElements(r2a, r2c);
  printVector(r2);
  printSuccess(compareVector(r2, e2));

  return 0;
}
