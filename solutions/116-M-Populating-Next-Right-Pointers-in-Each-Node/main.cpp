#include <iostream>
#include <queue>
#include <cmath>
#include "../../utilities/print-linked-list.cpp"

struct Node {
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int val): val(val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int val, Node* left, Node* right): val(val), left(left), right(right), next(nullptr) {}
};

Node* connect(Node* root) {
  std::queue<Node*> q;
  q.push(root);
  int level = 0;
  Node* previousNode = nullptr;
  Node* nextNode;

  while (!q.empty()) {
    for (int i = 0; i < std::pow(2, level); ++i) {
      nextNode = q.front();
      q.pop();
      if (nextNode == nullptr) {
        break;
      }
      q.push(nextNode->left);
      q.push(nextNode->right);
      if (previousNode != nullptr) {
        previousNode->next = nextNode;
      }
      previousNode = nextNode;
    }
    previousNode = nullptr;
    ++level;
  }
  return root;
}

int main() {
  Node* n7a = new Node(7);
  Node* n6a = new Node(6);
  Node* n5a = new Node(5);
  Node* n4a = new Node(4);
  Node* n3a = new Node(3, n6a, n7a);
  Node* n2a = new Node(2, n4a, n5a);
  Node* n1a = new Node(1, n2a, n3a);
  Node* r1 = connect(n1a);
  printLinkedList(r1);
  printLinkedList(r1->left);
  printLinkedList(r1->left->left);
  Node* r2 = connect(nullptr);
  printLinkedList(r2);
  return 0;
}
