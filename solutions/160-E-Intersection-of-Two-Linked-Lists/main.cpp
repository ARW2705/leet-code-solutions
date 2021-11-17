#include <iostream>
#include <stack>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-success.cpp"

std::stack<ListNode*> getStack(ListNode* node) {
  std::stack<ListNode*> stack;
  while (node) {
    stack.push(node);
    node = node->next;
  }
  return stack;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
  std::stack<ListNode*> stackA = getStack(headA);
  std::stack<ListNode*> stackB = getStack(headB);

  ListNode* nodeA;
  ListNode* nodeB;
  while (!stackA.empty() && !stackB.empty()) {
    nodeA = stackA.top();
    stackA.pop();
    nodeB = stackB.top();
    stackB.pop();
    if (nodeA != nodeB) {
      return nodeA->next;
    }
  }
  return nodeA == nodeB ? nodeA : nullptr;
}

int main() {
  ListNode* c8 = new ListNode(8);
  ListNode* c4 = new ListNode(4);
  ListNode* c5 = new ListNode(5);
  c8->next = c4;
  c4->next = c5;

  ListNode* a4 = new ListNode(4);
  ListNode* a1 = new ListNode(1);
  a4->next = a1;
  a1->next = c8;

  ListNode* b5 = new ListNode(5);
  ListNode* b6 = new ListNode(6);
  ListNode* b1 = new ListNode(1);
  b5->next = b6;
  b6->next = b1;
  b1->next = c8;

  ListNode* r1 = getIntersectionNode(a4, b5);
  printSuccess(r1 == c8);

  /*------------*/

  ListNode* c4b = new ListNode(4);
  ListNode* c2b = new ListNode(2);
  c2b->next = c4b;

  ListNode* a1bb = new ListNode(1);
  ListNode* a9b = new ListNode(9);
  ListNode* a1ba = new ListNode(1);
  a1ba->next = a9b;
  a9b->next = a1bb;
  a1bb->next = c2b;

  ListNode* b3b = new ListNode(3);
  b3b->next = c2b;

  ListNode* r2 = getIntersectionNode(a1ba, b3b);
  printSuccess(r2 == c2b);

  /*------------*/

  ListNode* a4c = new ListNode(4);
  ListNode* a6c = new ListNode(6);
  ListNode* a2c = new ListNode(2);
  a2c->next = a6c;
  a6c->next = a4c;

  ListNode* b5c = new ListNode(5);
  ListNode* b1c = new ListNode(1);
  b1c->next = b5c;

  ListNode* r3 = getIntersectionNode(a2c, b1c);
  printSuccess(r3 == nullptr);

  /*------------*/

  ListNode* a1d = new ListNode(1);

  ListNode* r4 = getIntersectionNode(a1d, a1d);
  printSuccess(r4 == a1d);

  return 0;
}
