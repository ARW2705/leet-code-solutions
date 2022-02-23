#include <iostream>
#include "../../utilities/singly-linked-node.hpp"
#include "../../utilities/build-linked-list.cpp"
#include "../../utilities/print-success.cpp"

// recursive
void pairSumHelper(ListNode*& frontNode, ListNode* endNode, int& maxSum) {
  if (endNode) {
    pairSumHelper(frontNode, endNode->next, maxSum);
    maxSum = std::max(maxSum, frontNode->val + endNode->val);
    frontNode = frontNode->next;
  }
}

int pairSum(ListNode* head) {
  int maxSum = 0;
  ListNode* frontNode = head;
  pairSumHelper(frontNode, head, maxSum);
  return maxSum;
}

// iterative
// int pairSum(ListNode* head) {
//   std::vector<int> v;
//   while (head) {
//     v.push_back(head->val);
//     head = head->next;
//   }
//
//   int maxSum = 0;
//   int size = v.size();
//   int mid = size / 2;
//   for (int i = 0; i < mid; ++i) {
//     maxSum = std::max(maxSum, v[i] + v[size - i - 1]);
//   }
//
//   return maxSum;
// }

int main() {
  std::vector<int> v1 { 5, 4, 2, 1 };
  ListNode* l1 = buildLinkedList(v1);
  printSuccess(pairSum(l1) == 6);

  std::vector<int> v2 { 4, 2, 2, 3 };
  ListNode* l2 = buildLinkedList(v2);
  printSuccess(pairSum(l2) == 7);

  std::vector<int> v3 { 1, 100000 };
  ListNode* l3 = buildLinkedList(v3);
  printSuccess(pairSum(l3) == 100001);

  return 0;
}
