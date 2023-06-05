#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

using namespace std;

int maxPower(string s) {
  int maxLen = 1;
  int currentCharIndex = 0;
  for (int i = 1; i < s.size() + 1; ++i) {
    if (i == s.size() || s[i] != s[currentCharIndex]) {
      maxLen = max(maxLen, i - currentCharIndex);
      currentCharIndex = i;
    }
  }

  return maxLen;
}

int main() {
  string s1 = "leetcode";
  printSuccess(maxPower(s1) == 2);

  string s2 = "abbcccddddeeeeedcba";
  printSuccess(maxPower(s2) == 5);

  string s3 = "j";
  printSuccess(maxPower(s3) == 1);

  string s4 = "cc";
  printSuccess(maxPower(s4) == 2);

  return 0;
}
