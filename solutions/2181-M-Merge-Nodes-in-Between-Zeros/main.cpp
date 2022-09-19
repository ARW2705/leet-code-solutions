#include <iostream>
#include <vector>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/build-linked-list.cpp"
#include "../../utilities/print-linked-list.cpp"

ListNode* mergeNodes(ListNode* head) {
  ListNode* current = head;
  ListNode* buildNode = head;
  while (current->next) {
    if (current->val == 0) {
      buildNode = current;
      current = current->next;
    } else {
      buildNode->val += current->val;
      ListNode* nextNode = current->next;
      delete current;
      buildNode->next = nextNode;
      current = nextNode;
    }
  }

  delete buildNode->next;
  buildNode->next = nullptr;
  return head;   
}

int main() {
  std::vector<int> v1 { 0, 3, 1, 0, 4, 5, 2, 0 };
  ListNode* ln1 = buildLinkedList(v1);
  ListNode* lnr1 = mergeNodes(ln1);
  printLinkedList(lnr1);

  std::vector<int> v2 { 0, 1, 0, 3, 0, 2, 2, 0 };
  ListNode* ln2 = buildLinkedList(v2);
  ListNode* lnr2 = mergeNodes(ln2);
  printLinkedList(lnr2);

  return 0;
}
