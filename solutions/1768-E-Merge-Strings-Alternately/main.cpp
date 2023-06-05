#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

std::string mergeAlternately(std::string word1, std::string word2) {
  std::string merged = "";
  int word1Index = 0, word2Index = 0;
  while (word1Index < word1.size() || word2Index < word2.size()) {
    if (word1Index < word1.size() && (word1Index <= word2Index || word2Index >= word2.size())) {
      merged += word1[word1Index];
      ++word1Index;
    } else {
      merged += word2[word2Index];
      ++word2Index;
    }
  }

  return merged;
}

int main() {
  std::string word1a = "abc";
  std::string word1b = "pqr";
  std::string r1 = mergeAlternately(word1a, word1b);
  printSuccess(r1.compare("apbqcr") == 0);

  std::string word2a = "ab";
  std::string word2b = "pqrs";
  std::string r2 = mergeAlternately(word2a, word2b);
  printSuccess(r2.compare("apbqrs") == 0);

  std::string word3a = "abcd";
  std::string word3b = "pq";
  std::string r3 = mergeAlternately(word3a, word3b);
  printSuccess(r3.compare("apbqcd") == 0);

  return 0;
}
