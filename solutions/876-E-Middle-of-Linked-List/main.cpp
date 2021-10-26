#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-linked-list.cpp"

ListNode* middleNodeHelper(ListNode* head, int currentSize, int& totalSize) {
  if (head != nullptr) {
    ListNode* foundNode = middleNodeHelper(head->next, currentSize + 1, ++totalSize);
    if (foundNode != nullptr) {
      return foundNode;
    } else if (totalSize / 2 == currentSize) {
      return head;
    } else {
      return nullptr;
    }
  }
  return head;
}

ListNode* middleNode(ListNode* head) {
  int currentSize = 0, totalSize = 0;
  return middleNodeHelper(head, currentSize, totalSize);
}

int main() {
  ListNode l5 = ListNode(5);
  ListNode l4 = ListNode(4, &l5);
  ListNode l3 = ListNode(3, &l4);
  ListNode l2 = ListNode(2, &l3);
  ListNode l1 = ListNode(1, &l2);
  ListNode* mid1 = middleNode(&l1);
  printLinkedList(mid1);
  std::cout << (mid1->val == 3 ? "PASS" : "FAIL") << "\n";

  ListNode l6 = ListNode(6);
  l5.next = &l6;
  ListNode* mid2 = middleNode(&l1);
  printLinkedList(mid2);
  std::cout << (mid2->val == 4 ? "PASS" : "FAIL") << "\n";
  return 0;
}
