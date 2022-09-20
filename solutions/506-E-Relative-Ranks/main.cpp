#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
  std::map<int, int, std::greater<int>> ranks;

  int size = score.size();
  for (int i = 0; i < size; ++i) {
    ranks[score[i]] = i;
  }

  std::vector<std::string> results(size);
  int counter = 1;
  for (auto rank : ranks) {
    if (counter == 1) results[rank.second] = "Gold Medal";
    else if (counter == 2) results[rank.second] = "Silver Medal";
    else if (counter == 3) results[rank.second] = "Bronze Medal";
    else results[rank.second] = std::to_string(counter);
    ++counter;
  }
  
  return results;
}

int main() {
  std::vector<int> v1 { 5, 4, 3, 2, 1 };
  std::vector<std::string> e1 { "Gold Medal", "Silver Medal", "Bronze Medal", "4", "5" };
  std::vector<std::string> r1 = findRelativeRanks(v1);
  printSuccess(compareVector(e1, r1));

  std::vector<int> v2 { 10, 3, 8, 9, 4 };
  std::vector<std::string> e2 { "Gold Medal", "5", "Bronze Medal", "Silver Medal", "4" };
  std::vector<std::string> r2 = findRelativeRanks(v2);
  printSuccess(compareVector(e2, r2));

  return 0;
}
