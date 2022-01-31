#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

int mostWordsFound(std::vector<std::string>& sentences) {
  int maxCount = 0, wordCount;
  for (std::string sentence : sentences) {
    wordCount = std::count(sentence.begin(), sentence.end(), ' ');
    maxCount = std::max(maxCount, wordCount);
  }
  return maxCount + 1;
}

int main() {
  std::vector<std::string> v1 {
    "alice and bob love leetcode",
    "i think so too",
    "this is great thanks very much"
  };
  printSuccess(mostWordsFound(v1) == 6);

  std::vector<std::string> v2 {
    "please wait",
    "continue to fight",
    "continue to win"
  };
  printSuccess(mostWordsFound(v2) == 3);

  return 0;
}
