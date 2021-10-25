#include <iostream>
#include <string>
#include <vector>

bool isAnagram(std::string s, std::string t) {
  if (s.size() != t.size()) {
    return false;
  }
  int letterCount = 26;
  std::vector<int> sCount(letterCount, 0);
  std::vector<int> tCount(letterCount, 0);
  for (int i = 0; i < s.size(); ++i) {
    sCount[s[i] - 'a']++;
    tCount[t[i] - 'a']++;
  }
  for (int i = 0; i < letterCount; ++i) {
    if (sCount[i] != tCount[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::string s1a = "anagram";
  std::string s1b = "nagaram";
  std::cout << (isAnagram(s1a, s1b) ? "PASS" : "FAIL") << "\n";

  std::string s2a = "rat";
  std::string s2b = "car";
  std::cout << (!isAnagram(s2a, s2b) ? "PASS" : "FAIL") << std::endl;

  return 0;
}
