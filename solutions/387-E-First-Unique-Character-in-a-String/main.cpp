#include <iostream>
#include <string>
#include <vector>

int firstUniqChar(std::string s) {
  std::vector<int> letters(26, 0);
  for (char c : s) {
    letters[c - 'a']++;
  }
  for (int i = 0; i < s.size(); ++i) {
    if (letters[s[i] - 'a'] == 1) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::string s1 = "leetcode";
  int e1 = 0;
  int r1 = firstUniqChar(s1);
  std::cout << s1 << ": " << r1 << " - " << std::boolalpha << (e1 == r1) << "\n";

  std::string s2 = "loveleetcode";
  int e2 = 2;
  int r2 = firstUniqChar(s2);
  std::cout << s2 << ": " << r2 << " - " << std::boolalpha << (e2 == r2) << "\n";

  std::string s3 = "aabb";
  int e3 = -1;
  int r3 = firstUniqChar(s3);
  std::cout << s3 << ": " << r3 << " - " << std::boolalpha << (e3 == r3) << "\n";
  return 0;
}
