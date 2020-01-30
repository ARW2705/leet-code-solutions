#include <iostream>
#include <string>

void printResult(std::string& input, std::string expected, std::string result) {
  std::cout
    << input
    << " to lower: "
    << result
    << ", expected "
    << expected
    << "\n"
    << (expected == result ? "PASS": "FAIL")
    << "\n";
}

// Do without builtin tolower
std::string toLowerCase(std::string str) {
    for (int i=0; i < str.size(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'a' - 'A' + str[i];
        }
    }
    return str;
}

int main() {
  std::string ex1 = "Hello";
  printResult(ex1, "hello", toLowerCase(ex1));

  std::string ex2 = "here";
  printResult(ex2, "here", toLowerCase(ex2));

  std::string ex3 = "LOVELY";
  printResult(ex3, "lovely", toLowerCase(ex3));
  return 0;
}
