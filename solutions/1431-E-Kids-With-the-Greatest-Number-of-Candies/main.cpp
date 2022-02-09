#include <iostream>
#include <vector>
#include "../../utilities/print-success.cpp"
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-vector.cpp"

std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
  int maxCandies = 0;
  for (int candy : candies) {
    if (candy > maxCandies) {
      maxCandies = candy;
    }
  }

  std::vector<bool> hasGreatest(candies.size());
  for (int i = 0; i < candies.size(); ++i) {
    hasGreatest[i] = candies[i] + extraCandies >= maxCandies;
  }
  return hasGreatest;
}

int main() {
  std::vector<int> v1 { 2, 3, 5, 1, 3 };
  std::vector<bool> e1 { true, true, true, false, true };
  std::vector<bool> r1 = kidsWithCandies(v1, 3);
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 { 4, 2, 1, 1, 2 };
  std::vector<bool> e2 { true, false, false, false, false };
  std::vector<bool> r2 = kidsWithCandies(v2, 1);
  printSuccess(compareVector(e2, r2));

  std::vector<int> v3 { 12, 1, 12 };
  std::vector<bool> e3 { true, false, true };
  std::vector<bool> r3 = kidsWithCandies(v3, 10);
  printSuccess(compareVector(e3, r3));
  return 0;
}
