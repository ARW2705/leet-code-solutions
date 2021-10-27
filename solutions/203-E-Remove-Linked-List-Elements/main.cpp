#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-linked-list.cpp"

// ListNode* removeElementsHelper(ListNode* node, int val) {
//   if (node != nullptr) {
//     ListNode* previousNode = removeElementsHelper(node->next, val);
//     if (previousNode != nullptr && previousNode->val == val) {
//       node->next = previousNode->next;
//       delete previousNode;
//     }
//   }
//   return node;
// }
//
// initial solution
// ListNode* removeElements(ListNode* head, int val) {
//   removeElementsHelper(head, val);
//   if (head != nullptr && head->val == val) {
//     ListNode* next = head->next;
//     delete head;
//     return next;
//   }
//   return head;
// }

// simplified solution
ListNode* removeElements(ListNode* head, int val) {
  if (head == nullptr) {
    return head;
  } else if (head->val == val) {
    return removeElements(head->next, val);
  } else {
    head->next = removeElements(head->next, val);
    return head;
  }
}

int main() {
  ListNode* l6a = new ListNode(6);
  ListNode* l5 = new ListNode(5, l6a);
  ListNode* l4 = new ListNode(4, l5);
  ListNode* l3 = new ListNode(3, l4);
  ListNode* l6b = new ListNode(6, l3);
  ListNode* l2 = new ListNode(2, l6b);
  ListNode* l1 = new ListNode(1, l2);
  ListNode* r1 = removeElements(l1, 6);
  printLinkedList(r1);

  ListNode* r2 = removeElements(nullptr, 1);
  printLinkedList(r2);

  ListNode* l7a = new ListNode(7);
  ListNode* l7b = new ListNode(7, l7a);
  ListNode* l7c = new ListNode(7, l7b);
  ListNode* l7d = new ListNode(7, l7c);
  ListNode* r3 = removeElements(l7d, 7);
  printLinkedList(r3);

  ListNode* m2 = new ListNode(2);
  ListNode* m1 = new ListNode(1, m2);
  ListNode* r4 = removeElements(m1, 1);
  printLinkedList(r4);

  return 0;
}
