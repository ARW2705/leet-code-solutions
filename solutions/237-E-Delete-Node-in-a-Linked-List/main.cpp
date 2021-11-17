#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-linked-list.cpp"


void deleteNode(ListNode* node) {
  while (node->next->next) {
    node->val = node->next->val;
    node = node->next;
  }
  ListNode* tail = node->next;
  node->val = tail->val;
  node->next = nullptr;
  delete tail;
}

int main() {
  ListNode* a9 = new ListNode(9);
  ListNode* a1 = new ListNode(1, a9);
  ListNode* a5 = new ListNode(5, a1);
  ListNode* a4 = new ListNode(4, a5);
  printLinkedList(a4);
  deleteNode(a5);
  printLinkedList(a4);
  std::cout << "\n";

  ListNode* b9 = new ListNode(9);
  ListNode* b1 = new ListNode(1, b9);
  ListNode* b5 = new ListNode(5, b1);
  ListNode* b4 = new ListNode(4, b5);
  printLinkedList(b4);
  deleteNode(b1);
  printLinkedList(b4);
  std::cout << "\n";

  ListNode* c4 = new ListNode(4);
  ListNode* c3 = new ListNode(3, c4);
  ListNode* c2 = new ListNode(2, c3);
  ListNode* c1 = new ListNode(1, c2);
  printLinkedList(c1);
  deleteNode(c3);
  printLinkedList(c1);
  std::cout << "\n";

  ListNode* d1 = new ListNode(1);
  ListNode* d0 = new ListNode(0, d1);
  printLinkedList(d0);
  deleteNode(d0);
  printLinkedList(d0);
  std::cout << "\n";

  ListNode* e99 = new ListNode(-99);
  ListNode* e5 = new ListNode(5, e99);
  ListNode* e3 = new ListNode(-3, e5);
  printLinkedList(e3);
  deleteNode(e3);
  printLinkedList(e3);

  return 0;
}
