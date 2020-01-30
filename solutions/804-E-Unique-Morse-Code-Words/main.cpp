#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

std::string getCodeFromWord(std::string word, std::vector<std::string>& codex) {
  std::string result = "";
  for (char c : word) {
    result.insert(result.size(), codex[c - 'a']);
  }
  return result;
}

int uniqueMorseRepresentations(std::vector<std::string>& words) {
  std::vector<std::string> codex {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
  std::unordered_set<std::string> uniqueCodes;
  for (std::string word : words) {
    uniqueCodes.insert(getCodeFromWord(word, codex));
  }
  return uniqueCodes.size();
}

int main() {
  std::vector<std::string> words { "gin", "zen", "gig", "msg" };
  int count = uniqueMorseRepresentations(words);
  std::cout
    << "For { \"gin\", \"zen\", \"gig\", \"msg\" } there should be 2 unique transformations, got "
    << count
    << "\n"
    << (count == 2 ? "PASS": "FAIL")
    << std::endl;
  return 0;
}
