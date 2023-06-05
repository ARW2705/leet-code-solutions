#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "../../utilities/print-success.cpp"


// Loop and search
// int arithmeticTriplets(std::vector<int>& nums, int diff) {
//   int tripletCount = 0;

//   for (int i = 0; i < nums.size() - 2; ++i) {
//     int next = nums[i] + diff;
//     if (std::find(nums.begin(), nums.end(), next) == nums.end()) continue;
//     int outer = next + diff;
//     if (std::find(nums.begin(), nums.end(), outer) != nums.end()) ++tripletCount;
//   }

//   return tripletCount;
// }

// memoize previous values
int arithmeticTriplets(std::vector<int>& nums, int diff) {
  int tripletCount = 0;
  std::unordered_set<int> previous({ nums[0], nums[1] });

  for (int i = 2; i < nums.size(); ++i) {
    if (
      previous.find(nums[i] - diff * 2) != previous.end()
      && previous.find(nums[i] - diff) != previous.end()
    ) {
      ++tripletCount;
    }

    previous.insert(nums[i]);
  }

  return tripletCount;
}

int main() {
  std::vector<int> v1 { 0, 1, 4, 6, 7, 10 };
  printSuccess(arithmeticTriplets(v1, 3) == 2);

  std::vector<int> v2 { 4, 5, 6, 7, 8, 9 };
  printSuccess(arithmeticTriplets(v2, 2) == 2);

  std::vector<int> v3 {1,2,3,7,10,12,14,16,17,18,20,22,23,24,25,27,29,30,35,36,38,39,40,42,45,46,47,48,50,52,53,56,57,58,59,60,61,63,67,69,70,71,72,77,78,79,80,81,82,83,84,86,87,89,93,97,98,100};
  printSuccess(arithmeticTriplets(v3, 11) == 23);

  return 0;
}
