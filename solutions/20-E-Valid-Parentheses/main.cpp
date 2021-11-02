#include <iostream>
#include <string>
#include <stack>

bool isValid(std::string s) {
  std::stack<char> parens;
  char last;
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      parens.push(c);
    } else if (parens.empty()) {
      return false;
    } else {
      last = parens.top();
      parens.pop();
      if (last != c - 1 && last != c - 2) {
        return false;
      }
    }
  }
  return parens.empty();
}

int main() {
  std::string s1 = "()";
  std::cout << (isValid(s1) ? "PASS" : "FAIL") << "\n";

  std::string s2 = "()[]{}";
  std::cout << (isValid(s2) ? "PASS" : "FAIL") << "\n";

  std::string s3 = "(]";
  std::cout << (!isValid(s3) ? "PASS" : "FAIL") << "\n";

  std::string s4 = "([)]";
  std::cout << (!isValid(s4) ? "PASS" : "FAIL") << "\n";

  std::string s5 = "{[]}";
  std::cout << (isValid(s5) ? "PASS" : "FAIL") << "\n";

  return 0;
}
