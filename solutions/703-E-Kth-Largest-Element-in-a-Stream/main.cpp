#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../../utilities/print-success.cpp"

class MyCompare {
public:
  bool operator() (const int& lhs, const int& rhs) {
    return lhs > rhs;
  }
};

class KthLargest {
public:
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  int kth;

  KthLargest(int k, std::vector<int>& nums) {
    kth = k;
    int size = nums.size();
    for (int num : nums) {
      pq.push(num);
    }
    if (size > k) {
      for (int i = 0; i < size - k; ++i) {
        pq.pop();
      }
    }
  }
  
  int add(int val) {
    if (pq.size() < kth) {
      pq.push(val);
    } else if (val > pq.top()) {
      pq.pop();
      pq.push(val);
    }
    return pq.top();
  }
};

int main() {
  std::vector<int> v1 {4, 5, 8, 2};
  KthLargest* kth = new KthLargest(3, v1);
  printSuccess(kth->add(3) == 4);
  printSuccess(kth->add(5) == 5);
  printSuccess(kth->add(10) == 5);
  printSuccess(kth->add(9) == 8);
  printSuccess(kth->add(4) == 8);
  std::cout << "\n";

  std::vector<int> v2 {};
  KthLargest* kth2 = new KthLargest(1, v2);
  printSuccess(kth2->add(-3) == -3);
  printSuccess(kth2->add(-2) == -2);
  printSuccess(kth2->add(-4) == -2);
  printSuccess(kth2->add(0) == 0);
  printSuccess(kth2->add(4) == 4);
  std::cout << "\n";

  std::vector<int> v3 { 0 };
  KthLargest* kth3 = new KthLargest(2, v3);
  printSuccess(kth3->add(-1) == -1);
  printSuccess(kth3->add(1) == 0);
  printSuccess(kth3->add(-2) == 0);
  printSuccess(kth3->add(-4) == 0);
  printSuccess(kth3->add(3) == 1);

  std::vector<int> v4 { -10, 1, 3, 1, 4, 10, 3, 9, 4, 5, 1 };
  // 10, 9, 5, 4, 4, 3, 3
  KthLargest* kth4 = new KthLargest(7, v4);
  printSuccess(kth4->add(3) == 3);

  return 0;
}
