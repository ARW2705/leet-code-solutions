#include <iostream>
#include <string>

bool containsInRange(std::string& s, char c, int startIndex, int endIndex) {
  for (int i = startIndex; i < endIndex; ++i) {
    if (s[i] == c) {
      return true;
    }
  }
  return false;
}

int lengthOfLongestSubstring(std::string s) {
  int leftIndex = 0, rightIndex = 0, maxLength = 0, currentMax = 0;
  char current;
  while (rightIndex < s.size()) {
    current = s[rightIndex];
    if (containsInRange(s, current, leftIndex, rightIndex)) {
      ++leftIndex;
    } else {
      ++rightIndex;
    }
    currentMax = rightIndex - leftIndex;
    if (currentMax > maxLength) {
      maxLength = currentMax;
    }
  }
  return maxLength;
}

int main() {
  std::string s1 = "abcabcbb";
  int r1 = lengthOfLongestSubstring(s1);
  std::cout << (r1 == 3 ? "PASS" : "FAIL") << "\n";

  std::string s2 = "bbbbb";
  int r2 = lengthOfLongestSubstring(s2);
  std::cout << (r2 == 1 ? "PASS" : "FAIL") << "\n";

  std::string s3 = "pwwkew";
  int r3 = lengthOfLongestSubstring(s3);
  std::cout << (r3 == 3 ? "PASS" : "FAIL") << "\n";

  std::string s4 = "";
  int r4 = lengthOfLongestSubstring(s4);
  std::cout << (r4 == 0 ? "PASS" : "FAIL") << "\n";
  return 0;
}
