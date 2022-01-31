#include <iostream>
#include <string>
#include <unordered_map>
#include "../../utilities/print-success.cpp"

bool wordPattern(std::string pattern, std::string s) {
  std::unordered_map<char, std::string> charToString;
  std::unordered_map<std::string, char> stringToChar;
  int nextStartIndex = 0;
  for (int i = 0; i < pattern.size(); ++i) {
    std::string nextString = "";
    for (int j = nextStartIndex; j < s.size(); ++j) {
      if (s[j] == ' ') {
        break;
      }
      nextString += s[j];
    }
    if (!nextString.size()) return false;
    nextStartIndex += nextString.size() + 1;
    std::unordered_map<char, std::string>::iterator charIter = charToString.find(pattern[i]);
    std::unordered_map<std::string, char>::iterator stringIter = stringToChar.find(nextString);
    if (charIter == charToString.end() && stringIter == stringToChar.end()) {
      charToString.insert(std::make_pair(pattern[i], nextString));
      stringToChar.insert(std::make_pair(nextString, pattern[i]));
    } else if (
      (charIter != charToString.end() && charIter->second.compare(nextString))
      || (stringIter != stringToChar.end() && stringIter->second != pattern[i])
    ) {
      return false;
    }
  }
  return nextStartIndex > s.size();
}

int main() {
  std::string p1 = "abba";
  std::string s1 = "dog cat cat dog";
  printSuccess(wordPattern(p1, s1));

  std::string p2 = "abba";
  std::string s2 = "dog cat cat fish";
  printSuccess(!wordPattern(p2, s2));

  std::string p3 = "aaaa";
  std::string s3 = "dog cat cat dog";
  printSuccess(!wordPattern(p3, s3));

  std::string p4 = "abba";
  std::string s4 = "dog dog dog dog";
  printSuccess(!wordPattern(p4, s4));

  std::string p5 = "aaa";
  std::string s5 = "aa aa aa aa";
  printSuccess(!wordPattern(p5, s5));

  std::string p6 = "aaa";
  std::string s6 = "aa aa";
  printSuccess(!wordPattern(p6, s6));

  std::string p7 = "abca";
  std::string s7 = "dog cat fish dog";
  printSuccess(wordPattern(p7, s7));

  std::string p8 = "he";
  std::string s8 = "unit";
  printSuccess(!wordPattern(p8, s8));

  return 0;
}
