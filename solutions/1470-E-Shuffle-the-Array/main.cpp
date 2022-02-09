#include <iostream>
#include <vector>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

std::vector<int> shuffle(std::vector<int>& nums, int n) {
  std::vector<int> result(nums.size());
  for (int i = 0; i < n; ++i) {
    result[i * 2] = nums[i];
    result[i * 2 + 1] = nums[i + n];
  }
  return result;
}

int main() {
  std::vector<int> v1 {2,5,1,3,4,7};
  std::vector<int> e1 {2,3,5,4,1,7};
  std::vector<int> r1 = shuffle(v1, 3);
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 {1,2,3,4,4,3,2,1};
  std::vector<int> e2 {1,4,2,3,3,2,4,1};
  std::vector<int> r2 = shuffle(v2, 4);
  printSuccess(compareVector(e2, r2));

  std::vector<int> v3 {1,1,2,2};
  std::vector<int> e3 {1,2,1,2};
  std::vector<int> r3 = shuffle(v3, 2);
  printSuccess(compareVector(e3, r3));

  std::vector<int> v4 {7,5,9,7,5,8,10,4,3,3,2,5,9,10};
  std::vector<int> e4 {7,4,5,3,9,3,7,2,5,5,8,9,10,10};
  std::vector<int> r4 = shuffle(v4, 7);
  printSuccess(compareVector(e4, r4));

  return 0;
}
