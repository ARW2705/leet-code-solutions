#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

int longestPalindrome(std::string s) {
  std::vector<int> letterCounts(52);
  for (char c : s) {
    if (c < 'a') {
      ++letterCounts[c - 'A'];
    } else {
      ++letterCounts[c - 'a' + 26];
    }
  }

  int letterCount = 0;
  int singleLetter = 0;
  for (int i = 0; i < letterCounts.size(); ++i) {
    if (letterCounts[i] % 2 == 0) {
      letterCount += letterCounts[i];
    } else {
      singleLetter = 1;
      if (letterCounts[i] > 1) {
        letterCount += letterCounts[i] - 1;
      }
    }
  }
  return letterCount + singleLetter;
}

int main() {
  printSuccess(longestPalindrome("abccccdd") == 7);
  printSuccess(longestPalindrome("a") == 1);
  printSuccess(longestPalindrome("bb") == 2);
  printSuccess(longestPalindrome("abcccdd") == 5);
  printSuccess(longestPalindrome("aabbcC") == 5);

  return 0;
}
