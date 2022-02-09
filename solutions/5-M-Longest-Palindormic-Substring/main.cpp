#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "../../utilities/print-success.cpp"

// bool isPalindrome(std::string& s, int start, int end) {
//   for (int i = 0; i < (end - start); ++i) {
//     if (s[start + i] != s[end - i]) {
//       return false;
//     }
//   }
//   return true;
// }
//
// std::string longestPalindrome(std::string s) {
//   int start = 0;
//   int end = 1;
//   for (int i = 0; i < s.size() - 1; ++i) {
//     for (int j = i + 1; j < s.size(); ++j) {
//       if (isPalindrome(s, i, j) && j - i + 1 > end - start) {
//         start = i;
//         end = j + 1;
//       }
//     }
//   }
//   return s.substr(start, (end - start));
// }

std::string longestPalindrome(std::string s) {
  int size = s.size();
  std::vector<std::vector<bool>> checkedPalindromes(size, std::vector<bool>(size, false));
  for (int i = 0; i < size; ++i) {
    checkedPalindromes[i][i] = true;
  }

  int start = 0;
  int end = 1;
  for (int i = size - 1; i >= 0; --i) {
    for (int j = i + 1; j < size; ++j) {
      if (s[i] == s[j]) {
        if (j - i == 1 || checkedPalindromes[i + 1][j - 1]) {
          checkedPalindromes[i][j] = true;
          if (j - i + 1 > end - start) {
            start = i;
            end = j + 1;
          }
        }
      }
    }
  }
  return s.substr(start, (end - start));
}

int main() {
  std::string s1 = "babad";
  std::string r1 = longestPalindrome(s1);
  std::cout << "\n" << s1 << " -> " << r1 << "\n\n";

  std::string s2 = "cbbd";
  std::string r2 = longestPalindrome(s2);
  std::cout << "\n" << s2 << " -> " << r2 << "\n\n";

  std::string s3 = "a";
  std::string r3 = longestPalindrome(s3);
  std::cout << "\n" << s3 << " -> " << r3 << "\n\n";

  std::string s4 = "ac";
  std::string r4 = longestPalindrome(s4);
  std::cout << "\n" << s4 << " -> " << r4 << "\n\n";

  std::string s5 = "abbcccbbbcaaccbababcbcabca";
  std::cout << "starting timer\n";
  std::chrono::high_resolution_clock::time_point start5 = std::chrono::high_resolution_clock::now();
  std::string r5 = longestPalindrome(s5);
  std::chrono::high_resolution_clock::time_point end5 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> timeSpan5 = std::chrono::duration_cast<std::chrono::duration<double>>(end5 - start5);
  std::cout << s5 << " -> " << r5 << " : " << timeSpan5.count() << "\n";

  std::string s6 = "aacabdkacaa";
  std::string r6 = longestPalindrome(s6);
  std::cout << s6 << " -> " << r6 << "\n";

  std::string s7 = "daomdukomcayjwgmmetypncdeixarhbectjcwftjjtwjrctixtrsehegwlfotpcdjysgfm";
  std::chrono::high_resolution_clock::time_point start7 = std::chrono::high_resolution_clock::now();
  std::string r7 = longestPalindrome(s7);
  std::chrono::high_resolution_clock::time_point end7 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> timeSpan7 = std::chrono::duration_cast<std::chrono::duration<double>>(end7 - start7);
  std::cout << r7 << " : " << timeSpan7.count() << "\n";

  std::string s8 = "ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
  std::chrono::high_resolution_clock::time_point start8 = std::chrono::high_resolution_clock::now();
  std::string r8 = longestPalindrome(s8);
  std::chrono::high_resolution_clock::time_point end8 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> timeSpan8 = std::chrono::duration_cast<std::chrono::duration<double>>(end8 - start8);
  std::cout << r8 << " : " << timeSpan8.count() << "\n";

  return 0;
}
