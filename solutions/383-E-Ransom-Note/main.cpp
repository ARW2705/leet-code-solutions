#include <iostream>
#include <string>
#include <vector>

bool canConstruct(std::string ransomNote, std::string magazine) {
  std::vector<int> neededLetters(26, 0);
  std::vector<int> availableLetters(26, 0);
  if (ransomNote.size() > magazine.size()) {
    return false;
  }
  for (int i = 0; i < magazine.size(); ++i) {
    if (i < ransomNote.size()) {
      neededLetters[ransomNote[i] - 'a']++;
    }
    availableLetters[magazine[i] - 'a']++;
  }
  for (int i = 0; i < neededLetters.size(); ++i) {
    if (availableLetters[i] < neededLetters[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::string s1a = "a";
  std::string s1b = "b";
  bool r1 = canConstruct(s1a, s1b);
  std::cout << (!r1 ? "PASS" : "FAIL") << "\n";

  std::string s2a = "aa";
  std::string s2b = "ab";
  bool r2 = canConstruct(s2a, s2b);
  std::cout << (!r2 ? "PASS" : "FAIL") << "\n";

  std::string s3a = "aa";
  std::string s3b = "aab";
  bool r3 = canConstruct(s3a, s3b);
  std::cout << (r3 ? "PASS" : "FAIL") << "\n";

  std::string s4a = "aa";
  std::string s4b = "a";
  bool r4 = canConstruct(s4a, s4b);
  std::cout << (!r4 ? "PASS" : "FAIL") << std::endl;

  return 0;
}
