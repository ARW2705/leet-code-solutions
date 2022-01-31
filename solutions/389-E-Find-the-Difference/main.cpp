#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

// char findTheDifference(std::string s, std::string t) {
//   std::vector<int> letters(26, 0);
//   for (int i = 0; i < t.size(); ++i) {
//     if (i < s.size()) {
//       --letters[s[i] - 'a'];
//     }
//     ++letters[t[i] - 'a'];
//   }
//   for (int i = 0; i < letters.size(); ++i) {
//     if (letters[i]) {
//       return i + 'a';
//     }
//   }
// }

char findTheDifference(std::string s, std::string t) {
  int sSum = 0, tSum = 0;
  for (int i = 0; i < t.size(); ++i) {
    if (i < s.size()) {
      sSum += s[i];
    }
    tSum += t[i];
  }
  return tSum - sSum;
}

int main() {
  std::string s1a = "abcd";
  std::string s1b = "abcde";
  printSuccess(findTheDifference(s1a, s1b) == 'e');

  std::string s2a = "";
  std::string s2b = "y";
  printSuccess(findTheDifference(s2a, s2b) == 'y');

  std::string s3a = "ae";
  std::string s3b = "aea";
  printSuccess(findTheDifference(s3a, s3b) == 'a');

  std::string s4a = "a";
  std::string s4b = "aa";
  printSuccess(findTheDifference(s4a, s4b) == 'a');

  return 0;
}
