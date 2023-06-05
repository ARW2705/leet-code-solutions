#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"

using namespace std;

bool isMonotonic(vector<int>& nums) {
  if (nums.size() == 1) return true;

  int direction = 0;
  for (int i = 1; i < nums.size(); ++i) {
    if (direction == 0 && nums[i] != nums[i - 1]) {
      direction = nums[i] > nums[i - 1] ? 1 : -1;
    }

    if ((nums[i] - nums[i - 1]) * direction < 0) return false;
  }

  return true;
}

int main() {
  vector<int> v1 { 1, 2, 2, 3 };
  printSuccess(isMonotonic(v1));

  vector<int> v2 { 6, 5, 4, 4 };
  printSuccess(isMonotonic(v2));

  vector<int> v3 { 1, 3, 2 };
  printSuccess(!isMonotonic(v3));

  vector<int> v4 { 1, 1, 2, 2, 3 };
  printSuccess(isMonotonic(v4));

  vector<int> v5 { 1 };
  printSuccess(isMonotonic(v5));

  vector<int> v6 { 5,3,2,4,1 };
  printSuccess(!isMonotonic(v6));

  return 0;
}
