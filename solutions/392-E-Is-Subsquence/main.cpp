#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

bool isSubsequence(std::string s, std::string t) {
  int sIndex = 0;
  for (int i = 0; i < t.size(); ++i) {
    if (s[sIndex] == t[i]) {
      ++sIndex;
    }
  }
  return sIndex == s.size();
}

int main() {
  std::string s1a = "abc";
  std::string s1b = "ahbgdc";
  printSuccess(isSubsequence(s1a, s1b));

  std::string s2a = "axc";
  std::string s2b = "ahbgdc";
  printSuccess(!isSubsequence(s2a, s2b));

  return 0;
}
