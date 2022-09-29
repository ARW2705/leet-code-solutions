#include <iostream>
#include <vector>
#include <string>
#include "../../utilities/print-success.cpp"
#include "../../utilities/print-vector.cpp"

void letterCombinationsHelper(std::vector<std::string>& letterArrays, int arrayIndex, std::string& combo, std::vector<std::string>& combinations, int digitSize) {
  if (arrayIndex >= letterArrays.size()) return;

  std::string letters = letterArrays[arrayIndex];
  for (int i = 0; i < letters.size(); ++i) {
    combo.push_back(letters[i]);
    letterCombinationsHelper(letterArrays, arrayIndex + 1, combo, combinations, digitSize);
    if (combo.size() == digitSize) combinations.push_back(combo);
    combo.pop_back();
  }
}

std::vector<std::string> letterCombinations(std::string digits) {
  std::vector<std::string> numPad = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

  std::vector<std::string> letters;
  for (char d : digits) {
    letters.push_back(numPad[d - '2']);
  }

  std::vector<std::string> combinations;
  std::string combo = "";
  letterCombinationsHelper(letters, 0, combo, combinations, digits.size());
  return combinations;
}

int main() {
  std::string s1 = "23";
  std::vector<std::string> r1 = letterCombinations(s1);
  printVector(r1);

  std::string s2 = "";
  std::vector<std::string> r2 = letterCombinations(s2);
  printVector(r2);

  std::string s3 = "2";
  std::vector<std::string> r3 = letterCombinations(s3);
  printVector(r3);

  return 0;
}
