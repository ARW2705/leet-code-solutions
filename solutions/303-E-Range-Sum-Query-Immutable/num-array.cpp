#include "num-array.hpp"

NumArray::NumArray(std::vector<int>& nums) {
  v = std::vector<int>(nums.size() + 1);
  v[0] = 0;
  for (int i = 0; i < nums.size(); ++i) {
    v[i + 1] = nums[i] + v[i];
  }
}

int NumArray::sumRange(int left, int right) {
  return v[right + 1] - v[left];
}
