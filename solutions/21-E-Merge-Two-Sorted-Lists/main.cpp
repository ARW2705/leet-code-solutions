#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-linked-list.cpp"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if (l1 != nullptr && l2 != nullptr) {
    if (l1->val > l2->val) {
      std::swap(l1, l2);
    }
    l1->next = mergeTwoLists(l1->next, l2);
  } else if (l1 == nullptr) {
    return l2;
  }
  return l1;
}

int main() {
  ListNode* l4a = new ListNode(4);
  ListNode* l2a = new ListNode(2, l4a);
  ListNode* l1a = new ListNode(1, l2a);
  ListNode* l4b = new ListNode(4);
  ListNode* l3b = new ListNode(3, l4b);
  ListNode* l1b = new ListNode(1, l3b);
  ListNode* r1 = mergeTwoLists(l1a, l1b);
  printLinkedList(r1);

  ListNode* r2 = mergeTwoLists(nullptr, nullptr);
  printLinkedList(r2);

  ListNode* l0 = new ListNode(0);
  ListNode* r3 = mergeTwoLists(nullptr, l0);
  printLinkedList(r3);

  return 0;
}
