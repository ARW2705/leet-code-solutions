#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#include "node.hpp"

void printVector(std::vector<int>& v) {
  std::cout << "[";
  for (size_t i=0; i < v.size(); ++i) {
    std::cout << v[i];
    if (i < v.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
}

bool compareVector(std::vector<int>& v1, std::vector<int>& v2) {
  if (v1.size() != v2.size()) return false;
  for (size_t i=0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

std::vector<int> postorderIterative(Node* root) {
  std::stack<Node*> nodeStack;
  std::vector<int> results;
  if (root != nullptr) {
    nodeStack.push(root);
  }
  while (!nodeStack.empty()) {
    Node* node = nodeStack.top();
    nodeStack.pop();
    results.push_back(node->val);
    for (auto stackIter = node->children.begin(); stackIter != node->children.end(); ++stackIter) {
      nodeStack.push(*stackIter);
    }
  }
  std::reverse(results.begin(), results.end());
  return results;
}

void postorderHelper(Node* node, std::vector<int>& container) {
  if (node == nullptr) return;
  for (size_t i=0; i < node->children.size(); ++i) {
    postorderHelper(node->children[i], container);
  }
  container.push_back(node->val);
}

std::vector<int> postorder(Node* root) {
  std::vector<int> container;
  postorderHelper(root, container);
  return container;
}

int main() {
  Node* leaf1 = new Node(5);
  Node* leaf2 = new Node(6);
  std::vector<Node*> children1 { leaf1, leaf2 };
  Node* subRoot1 = new Node(3, children1);

  Node* leaf3 = new Node(7);
  std::vector<Node*> children2 { leaf3 };
  Node* subRoot2 = new Node(2, children2);

  Node* leaf4 = new Node(4);
  std::vector<Node*> children3 { subRoot1, subRoot2, leaf4 };
  Node* root1 = new Node(1, children3);

  std::vector<int> expected1 = { 5, 6, 3, 7, 2, 4, 1 };

  std::vector<int> postorder1 = postorder(root1);
  printVector(postorder1);
  std::cout << "Recursive: " << (compareVector(expected1, postorder1) ? "PASS": "FAIL") << "\n";

  std::vector<int> postorder2 = postorderIterative(root1);
  printVector(postorder2);
  std::cout << "Iterative: " << (compareVector(expected1, postorder2) ? "PASS": "FAIL") << "\n";

  return 0;
}
