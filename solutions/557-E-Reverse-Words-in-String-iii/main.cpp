#include <iostream>
#include <string>

std::string reverseWords(std::string s) {
  std::string reversed = "";
  for (int i = 0, startIndex = 0; i < s.size() + 1; ++i) {
    if (s[i] == ' ' || i == s.size()) {
      for (int j = i - 1; j >= startIndex; --j) {
        reversed += s[j];
      }
      reversed += " ";
      startIndex = i + 1;
    }
  }
  reversed.pop_back();
  return reversed;
}

int main() {
  std::string t1 = "Let's take LeetCode contest";
  std::string e1 = "s'teL ekat edoCteeL tsetnoc";
  std::string r1 = reverseWords(t1);
  std::cout << r1 << ": " << (r1.compare(e1) == 0 ? "PASS" : "FAIL") << "\n";

  std::string t2 = "God Ding";
  std::string e2 = "doG gniD";
  std::string r2 = reverseWords(t2);
  std::cout << r2 << ": " << (r2.compare(e2) == 0 ? "PASS" : "FAIL") << "\n";
  return 0;
}
