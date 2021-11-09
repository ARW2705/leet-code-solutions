#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

int rob(std::vector<int>& nums) {
  int size = nums.size();
  if (size == 1) {
    return nums[0];
  } else {
    int maxAdjacent = nums[size - 2], maxNonAdjacent = nums[size - 1];
    int max = std::max(maxAdjacent, maxNonAdjacent);
    for (int i = size - 3; i >= 0; --i) {
      nums[i] += maxNonAdjacent;
      maxNonAdjacent = std::max(maxAdjacent, maxNonAdjacent);
      maxAdjacent = nums[i];
      if (nums[i] > max) {
        max = nums[i];
      }
    }
    return max;
  }
}

int main() {
  std::vector<int> h1 { 1, 2, 3, 1 };
  int r1 = rob(h1);
  std::cout << r1 << " ";
  printSuccess(r1 == 4);

  std::vector<int> h2 { 2, 7, 9, 3, 1 };
  int r2 = rob(h2);
  std::cout << r2 << " ";
  printSuccess(r2 == 12);

  std::vector<int> h3 { 1, 20, 1, 1, 20, 1, 1, 1 };
  int r3 = rob(h3);
  std::cout << r3 << " ";
  printSuccess(r3 == 41);

  std::vector<int> h4 { 1, 3, 1 };
  int r4 = rob(h4);
  std::cout << r4 << " ";
  printSuccess(r4 == 3);

  std::vector<int> h5 { 1, 3 };
  int r5 = rob(h5);
  std::cout << r5 << " ";
  printSuccess(r5 == 3);

  std::cout << std::endl;
  return 0;
}
