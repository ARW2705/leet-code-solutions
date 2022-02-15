#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"
#include "../../utilities/print-vector.cpp"

std::vector<std::string> commonChars(std::vector<std::string>& words) {
  std::vector<std::vector<int>> commonLetters(words.size(), std::vector<int>(26, 0));
  for (int i = 0; i < words.size(); ++i) {
    for (int j = 0; j < words[i].size(); ++j) {
      ++commonLetters[i][words[i][j] - 'a'];
    }
  }

  std::vector<std::string> result;
  for (int col = 0; col < 26; ++col) {
    int commonCount = std::numeric_limits<int>::max();
    for (int row = 0; row < commonLetters.size(); ++row) {
      commonCount = std::min(commonCount, commonLetters[row][col]);
    }
    if (commonCount) {
      for (int i = 0; i < commonCount; ++i) {
        result.push_back(std::string(1, col + 'a'));
      }
    }
  }

  return result;
}

int main() {
  std::vector<std::string> v1 { "bella", "label", "roller" };
  std::vector<std::string> e1 { "e", "l", "l" };
  std::vector<std::string> r1 = commonChars(v1);
  printSuccess(compareVector(e1, r1));

  std::vector<std::string> v2 { "cool", "lock", "cook" };
  std::vector<std::string> e2 { "c", "o" };
  std::vector<std::string> r2 = commonChars(v2);
  printSuccess(compareVector(e2, r2));

  std::vector<std::string> v3 { "acabcddd","bcbdbcbd","baddbadb","cbdddcac","aacbcccd","ccccddda","cababaab","addcaccd" };
  std::vector<std::string> e3 { };
  std::vector<std::string> r3 = commonChars(v3);
  printSuccess(compareVector(e3, r3));

  return 0;
}
