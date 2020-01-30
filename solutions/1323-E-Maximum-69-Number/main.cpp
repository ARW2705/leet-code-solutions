#include <iostream>
#include <string>
#include <cmath>

void printSuccess(int initial, int result, int expected) {
  std::cout << initial << " to " << result << " " << (result == expected ? "PASS": "FAIL") << "\n";
}

int maximum69Number(int num) {
  std::string numStr = std::to_string(num);
  for (int i=0; i < numStr.size(); ++i) {
    if (numStr[i] == '6') {
      return num + (3 * std::pow(10, numStr.size() - i - 1));
    }
  }
  return num;
}

int main() {
  int initial1 = 9669;
  int result1 = maximum69Number(initial1);
  printSuccess(initial1, result1, 9969);

  int initial2 = 9996;
  int result2 = maximum69Number(initial2);
  printSuccess(initial2, result2, 9999);

  int initial3 = 9999;
  int result3 = maximum69Number(initial3);
  printSuccess(initial3, result3, 9999);

  return 0;
}
