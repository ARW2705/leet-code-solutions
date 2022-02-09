#ifndef NUM_ARRAY_HPP
#define NUM_ARRAY_HPP

#include <vector>

class NumArray {
public:
  NumArray(std::vector<int>& nums);
  int sumRange(int left, int right);

private:
  std::vector<int> v;
};

#endif
