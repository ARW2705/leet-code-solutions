#include <iostream>
#include <vector>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/print-success.cpp"

bool isPalindromeHelper(ListNode* node1, ListNode*& node2) {
  if (!node1) {
    return true;
  } else if (isPalindromeHelper(node1->next, node2) && node1->val == node2->val) {
    node2 = node2->next;
    return true;
  }
  return false;
}

bool isPalindrome(ListNode* head) {
  ListNode* head2 = head;
  return isPalindromeHelper(head, head2);
}

// iterative solution with vector
// bool isPalindrome(ListNode* head) {
//   std::vector<int> vals;
//   while (head) {
//     vals.push_back(head->val);
//     head = head->next;
//   }
//   int size = vals.size();
//   for (int i = 0; i < size / 2; ++i) {
//     if (vals[i] != vals[size - i - 1]) {
//       return false;
//     }
//   }
//   return true;
// }

int main() {
  ListNode* a1b = new ListNode(1);
  ListNode* a2b = new ListNode(2, a1b);
  ListNode* a2a = new ListNode(2, a2b);
  ListNode* a1a = new ListNode(1, a2a);
  printSuccess(isPalindrome(a1a));

  ListNode* b2 = new ListNode(2);
  ListNode* b1 = new ListNode(1, b2);
  printSuccess(!isPalindrome(b1));

  ListNode* c1 = new ListNode(1);
  printSuccess(isPalindrome(c1));

  return 0;
}
