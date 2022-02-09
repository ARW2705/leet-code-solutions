#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-linked-list.cpp"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* head = new ListNode(0);
  ListNode* current = head;
  int carry = 0, sum;

  while (l1 || l2 || carry) {
    sum = carry;
    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }

    carry = sum > 9;
    current->next = new ListNode(sum % 10);
    current = current->next;
  }

  return head->next;
}

int main() {
  ListNode* l13a = new ListNode(3);
  ListNode* l14a = new ListNode(4, l13a);
  ListNode* l12a = new ListNode(2, l14a);

  ListNode* l14b = new ListNode(4);
  ListNode* l16b = new ListNode(6, l14b);
  ListNode* l15b = new ListNode(5, l16b);

  ListNode* r1 = addTwoNumbers(l12a, l15b);
  printLinkedList(r1);


  ListNode* l2a = new ListNode(0);

  ListNode* l2b = new ListNode(0);

  ListNode* r2 = addTwoNumbers(l2a, l2b);
  printLinkedList(r2);


  ListNode* l3a = new ListNode(9);
  ListNode* l3b = new ListNode(9, l3a);
  ListNode* l3c = new ListNode(9, l3b);
  ListNode* l3d = new ListNode(9, l3c);
  ListNode* l3e = new ListNode(9, l3d);
  ListNode* l3f = new ListNode(9, l3e);
  ListNode* l3g = new ListNode(9, l3f);

  ListNode* l3z = new ListNode(9);
  ListNode* l3y = new ListNode(9, l3z);
  ListNode* l3x = new ListNode(9, l3y);
  ListNode* l3w = new ListNode(9, l3x);

  ListNode* r3 = addTwoNumbers(l3g, l3w);
  printLinkedList(r3);


  ListNode* l4a = new ListNode(9);
  ListNode* l4b = new ListNode(9, l4a);
  ListNode* l4c = new ListNode(9, l4b);
  ListNode* l4d = new ListNode(9, l4c);
  ListNode* l4e = new ListNode(9, l4d);
  ListNode* l4f = new ListNode(9, l4e);
  ListNode* l4g = new ListNode(9, l4f);

  ListNode* l4z = new ListNode(9);
  ListNode* l4y = new ListNode(9, l4z);
  ListNode* l4x = new ListNode(9, l4y);
  ListNode* l4w = new ListNode(9, l4x);

  ListNode* r4 = addTwoNumbers(l4w, l4g);
  printLinkedList(r4);

  return 0;
}
