#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-linked-list.cpp"

int removeNthFromEndHelper(ListNode* head, int n) {
  if (head == nullptr) {
    return 0;
  }
  int fromEnd = removeNthFromEndHelper(head->next, n);
  if (fromEnd == n) {
    ListNode* tmp = head->next;
    head->next = head->next->next;
    delete tmp;
  }
  return fromEnd + 1;
}

ListNode* removeNthFromEndRecursive(ListNode* head, int n) {
  int fromEnd = removeNthFromEndHelper(head, n);
  if (fromEnd == n) {
    ListNode* tmp = head->next;
    delete head;
    return tmp;
  }
  return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* leader = head;
  ListNode* follower = head;
  while (leader->next != nullptr) {
    leader = leader->next;
    if (n == 0) {
      follower = follower->next;
    } else {
      --n;
    }
  }
  ListNode* tmp = follower->next;
  if (n == 1) {
    delete head;
    return tmp;
  } else {
    follower->next = follower->next->next;
    delete tmp;
    return head;
  }
}

int main() {
  ListNode* al1a = new ListNode(1);
  int n1 = 1;
  ListNode* r1 = removeNthFromEnd(al1a, n1);
  printLinkedList(r1);
  std::cout << (r1 == nullptr ? "PASS" : "FAIL") << "\n\n";

  ListNode* bl2 = new ListNode(2);
  ListNode* bl1b = new ListNode(1, bl2);
  int n2 = 1;
  ListNode* r2 = removeNthFromEnd(bl1b, n2);
  printLinkedList(r2);
  std::cout << (r2->val == 1 ? "PASS" : "FAIL") << "\n\n";

  ListNode* cl5 = new ListNode(5);
  ListNode* cl4 = new ListNode(4, cl5);
  ListNode* cl3 = new ListNode(3, cl4);
  ListNode* cl2 = new ListNode(2, cl3);
  ListNode* cl1 = new ListNode(1, cl2);
  int n3 = 2;
  ListNode* r3 = removeNthFromEnd(cl1, n3);
  printLinkedList(r3);
  std::cout << "\n";

  ListNode* dl2 = new ListNode(2);
  ListNode* dl1b = new ListNode(1, dl2);
  int n4 = 2;
  ListNode* r4 = removeNthFromEnd(dl1b, n4);
  printLinkedList(r4);
  std::cout << (r4->val == 2 ? "PASS" : "FAIL") << "\n";

  return 0;
}
