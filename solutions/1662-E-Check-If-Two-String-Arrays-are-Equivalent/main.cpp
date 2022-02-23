#include <iostream>
#include <vector>
#include <string>
#include "../../utilities/print-success.cpp"

bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
  std::string s1 = "";
  for (std::string word : word1) {
    s1 += word;
  }
  std::string s2 = "";
  for (std::string word : word2) {
    s2 += word;
  }
  return s1.compare(s2) == 0;
}

// bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
//   int word1Index = 0;
//   int letter1Index = 0;
//   int word2Index = 0;
//   int letter2Index = 0;
//   while (true) {
//     if (letter1Index >= word1[word1Index].size()) {
//       ++word1Index;
//       letter1Index = 0;
//     }
//     if (letter2Index >= word2[word2Index].size()) {
//       ++word2Index;
//       letter2Index = 0;
//     }
//     if (word1Index == word1.size() && word2Index == word2.size()) {
//       return true;
//     } else if (word1Index < word1.size() && word2Index < word2.size()) {
//       if (word1[word1Index][letter1Index] != word2[word2Index][letter2Index]) {
//         return false;
//       }
//       ++letter1Index;
//       ++letter2Index;
//     } else {
//       return false;
//     }
//   }
// }

int main() {
  std::vector<std::string> v1a { "ab", "c" };
  std::vector<std::string> v1b { "a", "bc" };
  printSuccess(arrayStringsAreEqual(v1a, v1b));

  std::vector<std::string> v2a { "a", "cb" };
  std::vector<std::string> v2b { "ab", "c" };
  printSuccess(!arrayStringsAreEqual(v2a, v2b));

  std::vector<std::string> v3a { "abc", "d", "defg" };
  std::vector<std::string> v3b { "abcddefg" };
  printSuccess(arrayStringsAreEqual(v3a, v3b));

  return 0;
}
