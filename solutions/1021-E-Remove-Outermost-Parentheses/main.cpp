#include <iostream>
#include <string>

void printResult(std::string& input, std::string expected, std::string result) {
  std::cout
    << "For "
    << input
    << ", expected "
    << expected
    << ", got "
    << result
    << "\n"
    << (expected == result ? "PASS": "FAIL")
    << "\n";
}

bool isPrimitive(std::string& str, int start, int end) {
    int gap = end - start;
    if (gap <= 6) {
        return gap != 2;
    } else {
        std::size_t indexOf = str.find(")(", start, 2);
        return (indexOf == std::string::npos) || (indexOf >= 2) || (end - indexOf <= 4);
    }
}

std::string removeOuterParentheses(std::string S) {
    std::string result = "";
    int start = 0;
    int end = 0;
    int balance = 0;
    for (char c : S) {
        ++end;
        if (c == ')') {
            --balance;
        } else {
            ++balance;
        }
        if (balance == 0) {
            if (isPrimitive(S, start, end - 1)) {
                for (int i=start + 1; i < end - 1; ++i) {
                    result.push_back(S[i]);
                }
            }
            start = end;
        }
    }
    return result;
}

int main() {
  std::string ex1 = "(()())(())";
  printResult(ex1, "()()()", removeOuterParentheses(ex1));

  std::string ex2 = "(()())(())(()(()))";
  printResult(ex2, "()()()()(())", removeOuterParentheses(ex2));

  std::string ex3 = "()()";
  printResult(ex3, "", removeOuterParentheses(ex3));
  return 0;
}
