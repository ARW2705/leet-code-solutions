#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

std::string restoreString(std::string s, std::vector<int>& indices) {
  std::string result(s);
  for (int i = 0; i < indices.size(); ++i) {
    result[indices[i]] = s[i];
  }
  return result;
}

int main() {
  std::string s1 = "codeleet";
  std::vector<int> v1 { 4, 5, 6, 7, 0, 2, 1, 3 };
  printSuccess(restoreString(s1, v1).compare("leetcode") == 0);

  std::string s2 = "abc";
  std::vector<int> v2 { 0, 1, 2 };
  printSuccess(restoreString(s2, v2).compare("abc") == 0);

  return 0;
}
