#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-vector.cpp"

// using map
// std::vector<int> numberOfPairs(std::vector<int>& nums) {
//   std::unordered_map<int, int> previous;
//   for (int num : nums) {
//     ++previous[num];
//   }

//   int pairCount = 0, uniqueCount = 0;
//   for (auto pnum : previous) {
//     pairCount += pnum.second / 2;
//     uniqueCount += pnum.second % 2;
//   }

//   return { pairCount, uniqueCount };
// }

// single iteration
std::vector<int> numberOfPairs(std::vector<int>& nums) {
  std::vector<int> previous(101, 0);
  int pairCount = 0, uniqueCount = 0;
  for (int num : nums) {
    if (previous[num] == 0) {
      ++uniqueCount;
      ++previous[num];
    } else {
      ++pairCount;
      --uniqueCount;
      --previous[num];
    }
  }

  return { pairCount, uniqueCount };
}

int main() {
  std::vector<int> v1 { 1, 3, 2, 1, 3, 2, 2 };
  std::vector<int> e1 { 3, 1 };
  std::vector<int> r1 = numberOfPairs(v1);
  printVector(r1);
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 { 1, 1 };
  std::vector<int> e2 { 1, 0 };
  std::vector<int> r2 = numberOfPairs(v2);
  printSuccess(compareVector(e2, r2));

  std::vector<int> v3 { 0 };
  std::vector<int> e3 { 0, 1 };
  std::vector<int> r3 = numberOfPairs(v3);
  printSuccess(compareVector(e3, r3));

  std::vector<int> v4 { 0, 1 };
  std::vector<int> e4 { 0, 2 };
  std::vector<int> r4 = numberOfPairs(v4);
  printVector(r4);
  printSuccess(compareVector(e4, r4));

  std::vector<int> v5 { 66,73,100,14,42 };
  std::vector<int> e5 { 0, 5 };
  std::vector<int> r5 = numberOfPairs(v5);
  printVector(r5);
  printSuccess(compareVector(e5, r5));

  return 0;
}
