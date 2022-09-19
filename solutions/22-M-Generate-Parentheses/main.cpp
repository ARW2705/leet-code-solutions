#include <iostream>
#include <vector>
#include <string>
#include "../../utilities/print-vector.cpp"

void generateParenthesisHelper(int openRemaining, int closeRemaining, std::string& current, std::vector<std::string>& results) {
  if (openRemaining || closeRemaining) {
    if (openRemaining) {
      current.push_back('(');
      generateParenthesisHelper(openRemaining - 1, closeRemaining, current, results);
      current.pop_back();
    }

    if (closeRemaining > openRemaining) {
      current.push_back(')');
      generateParenthesisHelper(openRemaining, closeRemaining - 1, current, results);
      current.pop_back();
    }
  } else {
    results.push_back(current);
  }
}

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::string> results;
  std::string current = "";
  generateParenthesisHelper(n, n, current, results);
  return results;
}

int main() {
  std::vector<std::string> r1 = generateParenthesis(3);
  printVector(r1);

  std::vector<std::string> r2 = generateParenthesis(1);
  printVector(r2);

  return 0;
}
