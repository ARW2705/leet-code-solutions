#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-linked-list.cpp"

ListNode* deleteDuplicates(ListNode* head) {
  if (head != nullptr) {
    ListNode* previousNode = deleteDuplicates(head->next);
    if (previousNode != nullptr && head->val == previousNode->val) {
      head->next = previousNode->next;
      delete previousNode;
    }
  }
  return head;
}

int main() {
  ListNode* l2 = new ListNode(2);
  ListNode* l1b = new ListNode(1, l2);
  ListNode* l1a = new ListNode(1, l1b);
  ListNode* r1 = deleteDuplicates(l1a);
  printLinkedList(r1);

  ListNode* m3b = new ListNode(3);
  ListNode* m3a = new ListNode(3, m3b);
  ListNode* m2 = new ListNode(2, m3a);
  ListNode* m1b = new ListNode(1, m2);
  ListNode* m1a = new ListNode(1, m1b);
  ListNode* r2 = deleteDuplicates(m1a);
  printLinkedList(r2);

  return 0;
}
