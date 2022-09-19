#include <iostream>
#include <vector>
#include <string>
#include "../../utilities/print-vector.cpp"

std::vector<std::string> findWords(std::vector<std::string>& words) {
  std::vector<int> charRows {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
  std::vector<std::string> result;

  for (std::string word : words) {
    int row, current, next;
    char c;
    for (int i = 0; i < word.size(); ++i) {
      c = word[i];
      current = charRows[c < 'a' ? c - 'A' : c - 'a'];
      if (i == 0) {
        row = current;
      }
      next = current;
      if (row != next) break;
    }

    if (row == next) {
      result.push_back(word);
    }
  }

  return result;
}

int main() {
  std::vector<std::string> words1 = { "Hello","Alaska","Dad","Peace" };
  std::vector<std::string> result1 = findWords(words1);
  printVector(result1);

  std::vector<std::string> words2 = { "omk" };
  std::vector<std::string> result2 = findWords(words2);
  printVector(result2);

  std::vector<std::string> words3 = { "adsdf", "sfd" };
  std::vector<std::string> result3 = findWords(words3);
  printVector(result3);

  std::vector<std::string> words4 = { "a", "b" };
  std::vector<std::string> result4 = findWords(words4);
  printVector(result4);

  std::vector<std::string> words5 = { "asdfghjkl", "qwertyuiop", "zxcvbnm" };
  std::vector<std::string> result5 = findWords(words5);
  printVector(result5);

  return 0;
}
