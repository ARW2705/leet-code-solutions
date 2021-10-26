#include <iostream>
#include <unordered_set>
#include "../../utilities/singly-linked-node.hpp"

bool hasCycle(ListNode* head) {
  std::unordered_set<ListNode*> previousNodes;
  ListNode* current = head;
  while (current != nullptr) {
    if (previousNodes.find(current) == previousNodes.end()) {
      previousNodes.insert(current);
      current = current->next;
    } else {
      return true;
    }
  }
  return false;
}

int main() {
  ListNode* n4 = new ListNode(4);
  ListNode* n0 = new ListNode(0, n4);
  ListNode* n2 = new ListNode(2, n0);
  ListNode* n3 = new ListNode(3, n2);
  n4->next = n2;
  bool r1 = hasCycle(n3);
  std::cout << (r1 ? "PASS" : "FAIL") << "\n";

  ListNode* o2 = new ListNode(2);
  ListNode* o1 = new ListNode(1, o2);
  o1->next = o1;
  bool r2 = hasCycle(o1);
  std::cout << (r2 ? "PASS" : "FAIL") << "\n";

  ListNode* p1 = new ListNode(1);
  bool r3 = hasCycle(p1);
  std::cout << (!r3 ? "PASS" : "FAIL") << "\n";

  ListNode* q6 = new ListNode(6);
  ListNode* q5 = new ListNode(5, q6);
  ListNode* q4 = new ListNode(4, q5);
  ListNode* q3 = new ListNode(3, q4);
  ListNode* q2 = new ListNode(2, q3);
  ListNode* q1 = new ListNode(1, q2);
  q5->next = q1;
  std::cout << (hasCycle(q1) ? "PASS" : "FAIL") << std::endl;

  return 0;
}
