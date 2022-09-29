#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"

std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
  std::sort(deck.begin(), deck.end());
  int size = deck.size();
  std::vector<int> newOrder(size);

  int mid = size / 2;
  int index = 0;
  for (; index < mid + (size % 2 == 1 ? 1 : 0); ++index) {
    newOrder[index * 2] = deck[index];
  }

  std::deque<int> dq;
  for (int i = 0; i < mid; ++i) {
    dq.push_back(2 * i + 1);
  }

  if (deck.size() % 2 == 1) {
    dq.push_back(dq.front());
    dq.pop_front();
  }

  int front;
  while (!dq.empty()) {
    newOrder[dq.front()] = deck[index++];
    dq.pop_front();
    front = dq.front();
    dq.pop_front();
    dq.push_back(front);
  }

  return newOrder;
}

int main() {
  std::vector<int> v1 {17,13,11,2,3,5,7};
  std::vector<int> e1 {2,13,3,11,5,17,7};
  std::vector<int> r1 = deckRevealedIncreasing(v1);
  printSuccess(compareVector(r1, e1));

  std::vector<int> v2 {1, 1000};
  std::vector<int> e2 {1, 1000};
  std::vector<int> r2 = deckRevealedIncreasing(v2);
  printSuccess(compareVector(r2, e2));

  std::vector<int> v3 {1, 2, 3, 4};
  std::vector<int> e3 {1, 3,2, 4};
  std::vector<int> r3 = deckRevealedIncreasing(v3);
  printSuccess(compareVector(r3, e3));

  std::vector<int> v4 {1,2, 3, 4,5,6,7,8,9};
  std::vector<int> e4 {1,9,2,6,3,8,4,7,5};
  std::vector<int> r4 = deckRevealedIncreasing(v4);
  printSuccess(compareVector(r4, e4));

  return 0;
}
