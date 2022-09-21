#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

// Definition for a Node.
class Node {
public:
  int val;
  std::vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

int maxDepth(Node* root) {
  if (!root) return 0;

  int maxSoFar = 0, depth;
  for (Node* node : root->children) {
    depth = maxDepth(node);
    if (depth > maxSoFar) {
      maxSoFar = depth;
    }
  }

  return maxSoFar + 1;
}

int main() {
  Node* n6 = new Node(6);
  Node* n5 = new Node(5);
  Node* n3 = new Node(3, { n5, n6 });
  Node* n2 = new Node(2);
  Node* n4 = new Node(4);
  Node* n1 = new Node(1, { n3, n2, n4 });
  printSuccess(maxDepth(n1) == 3);

  Node* m14 = new Node(14);
  Node* m11 = new Node(11, { m14 });
  Node* m12 = new Node(12);
  Node* m13 = new Node(13);
  Node* m6 = new Node(6);
  Node* m7 = new Node(7, { m11 });
  Node* m8 = new Node(8, { m12 });
  Node* m9 = new Node(9, { m13 });
  Node* m10 = new Node(10);
  Node* m2 = new Node(2);
  Node* m3 = new Node(3, { m6, m7 });
  Node* m4 = new Node(4, { m8 });
  Node* m5 = new Node(5, { m9, m10 });
  Node* m1 = new Node(1, { m2, m3, m4, m5 });
  printSuccess(maxDepth(m1) == 5);

  return 0;
}
