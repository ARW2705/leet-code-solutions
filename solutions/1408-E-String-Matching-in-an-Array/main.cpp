#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-success.cpp"

bool isSubstring(std::string& substr, std::string& source) {
  int substrSize = substr.size();
  int sourceSize = source.size();
  for (int i = 0; i < sourceSize - substrSize + 1; ++i) {
    if (source.compare(i, substrSize, substr) == 0) {
      return true;
    }
  }
  return false;
}

std::vector<std::string> stringMatching(std::vector<std::string>& words) {
  std::sort(words.begin(), words.end(), [](std::string a, std::string b) { return a.size() < b.size(); });
  std::vector<std::string> matches;
  int size = words.size();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (isSubstring(words[i], words[j])) {
        matches.push_back(words[i]);
        break;
      }
    }
  }
  return matches;
}

int main() {
  std::vector<std::string> v1 { "mass", "as", "hero", "superhero" };
  std::vector<std::string> e1 { "as", "hero" };
  std::vector<std::string> r1 = stringMatching(v1);
  printSuccess(compareVector(r1, e1));

  std::vector<std::string> v2 { "leetcode", "et", "code" };
  std::vector<std::string> e2 { "et", "code" };
  std::vector<std::string> r2 = stringMatching(v2);
  printSuccess(compareVector(r2, e2));

  std::vector<std::string> v3 { "blue", "green", "bu" };
  std::vector<std::string> e3;
  std::vector<std::string> r3 = stringMatching(v3);
  printSuccess(compareVector(r3, e3));

  std::vector<std::string> v4 {"leetcoder","leetcode","od","hamlet","am"};
  std::vector<std::string> e4 {"od","am","leetcode"};
  std::vector<std::string> r4 = stringMatching(v4);
  printSuccess(compareVector(r4, e4));

  std::vector<std::string> v5 {"eeeet","eeet"};
  std::vector<std::string> e5 {"eeet"};
  std::vector<std::string> r5 = stringMatching(v5);
  printSuccess(compareVector(r5, e5));

  return 0;
}
