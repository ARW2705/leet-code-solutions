#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-linked-list.cpp"

void swapNodes(ListNode* n1, ListNode* n2) {
  ListNode* tmp = n2->next;
  n2->next = n1;
  n1->next = tmp;
}

ListNode* reverseListHelper(ListNode* node, ListNode*& newHead) {
  if (node->next == nullptr) {
    newHead = node;
  } else {
    swapNodes(node, reverseListHelper(node->next, newHead));
  }
  return node;
}

ListNode* reverseList(ListNode* head) {
  ListNode* newHead = nullptr;
  if (head != nullptr) {
    reverseListHelper(head, newHead);
  }
  return newHead;
}

int main() {
  ListNode* a5 = new ListNode(5);
  ListNode* a4 = new ListNode(4, a5);
  ListNode* a3 = new ListNode(3, a4);
  ListNode* a2 = new ListNode(2, a3);
  ListNode* a1 = new ListNode(1, a2);
  printLinkedList(a1);
  ListNode* r1 = reverseList(a1);
  printLinkedList(r1);

  ListNode* b2 = new ListNode(2);
  ListNode* b1 = new ListNode(1, b2);
  printLinkedList(b1);
  ListNode* r2 = reverseList(b1);
  printLinkedList(r2);

  ListNode* c1 = nullptr;
  printLinkedList(c1);
  ListNode* r3 = reverseList(c1);
  printLinkedList(r3);

  std::cout << std::endl;
  return 0;
}
