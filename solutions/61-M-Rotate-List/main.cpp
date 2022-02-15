#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-linked-list.cpp"

int getListLength(ListNode* node) {
  int length = 0;
  while(node) {
    ++length;
    node = node->next;
  }
  return length;
}

ListNode* rotateRight(ListNode* head, int k) {
  if (!head) {
    return head;
  }

  int length = getListLength(head);
  int netRotations = k % length;
  if (!netRotations) {
    return head;
  }

  ListNode* newEnd = head;
  for (int i = 1; i < (length - netRotations); ++i) {
    newEnd = newEnd->next;
  }

  ListNode* newHead = newEnd->next;
  ListNode* attachPreviousHead = newHead;
  newEnd->next = nullptr;
  for (int i = 0; i < netRotations - 1; ++i) {
    attachPreviousHead = attachPreviousHead->next;
  }

  attachPreviousHead->next = head;
  return newHead;
}

int main() {
  ListNode* a5 = new ListNode(5);
  ListNode* a4 = new ListNode(4, a5);
  ListNode* a3 = new ListNode(3, a4);
  ListNode* a2 = new ListNode(2, a3);
  ListNode* a1 = new ListNode(1, a2);

  ListNode* a3e = new ListNode(3);
  ListNode* a2e = new ListNode(2, a3e);
  ListNode* a1e = new ListNode(1, a2e);
  ListNode* a5e = new ListNode(5, a1e);
  ListNode* a4e = new ListNode(4, a5e);

  ListNode* ar1 = rotateRight(a1, 2);
  std::cout << "expected: ";
  printLinkedList(a4e);
  std::cout << "result:   ";
  printLinkedList(ar1);

  ListNode* b2 = new ListNode(2);
  ListNode* b1 = new ListNode(1, b2);
  ListNode* b0 = new ListNode(0, b1);

  ListNode* b1e = new ListNode(1);
  ListNode* b0e = new ListNode(0, b1e);
  ListNode* b2e = new ListNode(2, b0e);

  ListNode* br1 = rotateRight(b0, 1);
  std::cout << "expected: ";
  printLinkedList(b2e);
  std::cout << "result:   ";
  printLinkedList(br1);

  ListNode* cr1 = rotateRight(nullptr, 3);
  std::cout << "for empty list: " << (cr1 == nullptr ? "PASS" : "FAIL") << "\n";

  ListNode* d1 = new ListNode(1);
  ListNode* dr1 = rotateRight(d1, 0);
  printLinkedList(dr1);

  ListNode* e2 = new ListNode(2);
  ListNode* e1 = new ListNode(1, e2);

  std::cout << "expected: ";
  printLinkedList(e1);
  ListNode* er1 = rotateRight(e1, 1);
  std::cout << "result:   ";
  printLinkedList(er1);

  return 0;
}
