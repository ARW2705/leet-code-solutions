#include <iostream>
#include <string>

void printResult(std::string& input, std::string& expected, std::string& result) {
  std::cout
    << "From "
    << input
    << ", expected "
    << expected
    << ", got "
    << result
    << ": \n"
    << (expected == result ? "PASS": "FAIL")
    << "\n";
}

std::string defangIPaddr(std::string address) {
    std::string defanged = "";
    for (char c : address) {
        if (c == '.') {
            defanged.insert(defanged.size(), "[.]");
        } else {
            defanged.push_back(c);
        }
    }
    return defanged;
}

int main() {
  std::string ex1 = "1.1.1.1";
  std::string expected1 = "1[.]1[.]1[.]1";
  std::string result1 = defangIPaddr(ex1);
  printResult(ex1, expected1, result1);

  std::string ex2 = "255.100.50.0";
  std::string expected2 = "255[.]100[.]50[.]0";
  std::string result2 = defangIPaddr(ex2);
  printResult(ex2, expected2, result2);
  return 0;
}
