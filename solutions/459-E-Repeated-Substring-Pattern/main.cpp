#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

bool isRepeating(std::string& s, std::string& substr) {
  int size = s.size();
  int subSize = substr.size();
  int blockCount = size / subSize;
  for (int i = 0; i < blockCount; ++i) {
    for (int j = 0; j < subSize; ++j) {
      if (s[i * subSize + j] != substr[j]) {
        return false;
      }
    }
  }
  return true;
}

bool repeatedSubstringPattern(std::string s) {
  if (s.size() == 1) {
    return false;
  }
  std::string substr = "";
  int mid = s.size() / 2;
  for (int i = 0; i < mid; ++i) {
    substr += s[i];
    if (s.size() % substr.size() == 0 && isRepeating(s, substr)) {
      return true;
    }
  }
  return false;
}

int main() {
  std::string s1 = "abab";
  printSuccess(repeatedSubstringPattern(s1));

  std::string s2 = "aba";
  printSuccess(!repeatedSubstringPattern(s2));

  std::string s3 = "abcabcabcabc";
  printSuccess(repeatedSubstringPattern(s3));

  std::string s4 = "a";
  printSuccess(!repeatedSubstringPattern(s4));

  std::string s5 = "ababab";
  printSuccess(repeatedSubstringPattern(s5));

  return 0;
}
