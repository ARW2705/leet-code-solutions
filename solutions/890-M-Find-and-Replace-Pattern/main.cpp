#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../../utilities/print-vector.cpp"

bool isPatternMatch(std::string& word, std::string& pattern) {
  std::unordered_map<char, char> patternToWord, wordToPattern;
  for (int i = 0; i < word.size(); ++i) {
    if (
      (patternToWord.count(pattern[i]) && patternToWord[pattern[i]] != word[i])
      || (wordToPattern.count(word[i]) && wordToPattern[word[i]] != pattern[i])
    ) {
      return false;
    } else {
      patternToWord[pattern[i]] = word[i];
      wordToPattern[word[i]] = pattern[i];
    }
  }
  return true;
}

std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
  std::vector<std::string> results;
  for (std::string word : words) {
    if (isPatternMatch(word, pattern)) {
      results.push_back(word);
    }
  }
  return results;
}

int main() {
  std::vector<std::string> v1 {"abc","deq","mee","aqq","dkd","ccc"};
  std::vector<std::string> e1 {"mee", "aqq"};
  std::vector<std::string> r1 = findAndReplacePattern(v1, "abb");
  printVector(r1);

  std::vector<std::string> v2 {"a","b","c"};
  std::vector<std::string> e2 {"a","b","c"};
  std::vector<std::string> r2 = findAndReplacePattern(v2, "a");
  printVector(r2);

  return 0;
}
