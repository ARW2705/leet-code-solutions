#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <set>
#include "../../utilities/print-vector.cpp"

void letterCasePermutationHelper(std::string& s, std::vector<std::string>& permutations, std::set<std::string>& previousPermutations) {
  for (int i = 0; i < s.size(); ++i) {
    if (std::isalpha(s[i])) {
      bool shouldUppercase = std::islower(s[i]);
      char c = s[i];
      s[i] = shouldUppercase ? std::toupper(c) : std::tolower(c);
      if (previousPermutations.find(s) == previousPermutations.end()) {
        permutations.push_back(s);
        previousPermutations.insert(s);
        letterCasePermutationHelper(s, permutations, previousPermutations);
      }
      c = shouldUppercase ? std::tolower(c) : std::toupper(c);
      s[i] = c;
    }
  }
}

std::vector<std::string> letterCasePermutation(std::string s) {
  std::vector<std::string> permutations;
  std::set<std::string> previousPermutations;
  letterCasePermutationHelper(s, permutations, previousPermutations);
  if (permutations.size() == 0) {
    permutations.push_back(s);
  }
  return permutations;
}

int main() {
  std::string s1 = "a1b2";
  std::vector<std::string> e1 = { "a1b2", "a1B2", "A1b2", "A1B2" };
  std::vector<std::string> r1 = letterCasePermutation(s1);
  printVector(r1);

  std::string s2 = "3z4";
  std::vector<std::string> e2 = { "3z4", "3Z4" };
  std::vector<std::string> r2 = letterCasePermutation(s2);
  printVector(r2);

  std::string s3 = "0";
  std::vector<std::string> e3 = { "0" };
  std::vector<std::string> r3 = letterCasePermutation(s3);
  printVector(r3);

  std::string s4 = "a1b2c3";
  std::vector<std::string> e4 = { "a1b2c3", "A1b2c3", "A1B2c3", "A1B2C3", "A1b2C3", "a1B2C3", "a1b2C3", "a1B2c3" };
  std::vector<std::string> r4 = letterCasePermutation(s4);
  printVector(r4);

  std::string s5 = "12345";
  std::vector<std::string> e5 = { "12345" };
  std::vector<std::string> r5 = letterCasePermutation(s5);
  printVector(r5);

  std::string s6 = "C";
  std::vector<std::string> e6 = { "c", "C" };
  std::vector<std::string> r6 = letterCasePermutation(s6);
  printVector(r6);
  return 0;
}
