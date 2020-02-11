#include <iostream>
#include <string>
#include <vector>

bool compareVectors(std::vector<int>& v1, std::vector<int>& v2) {
  for (size_t i=0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

std::string printVector(std::vector<int>& v) {
  std::string result = "[";
  for (size_t i=0; i < v.size(); ++i) {
    result += std::to_string(v[i]);
    if (i < v.size() - 1) {
      result += ", ";
    }
  }
  result += "]";
  return result;
}

void printResult(std::vector<int>& expected, std::vector<int>& result, std::string& input) {
  std::cout
    << "For \""
    << input
    << "\", got "
    << printVector(result)
    << "\n"
    << (compareVectors(expected, result) ? "PASS": "FAIL")
    << "\n";
}

std::vector<int> diStringMatch(std::string S) {
  int min = 0;
  int max = S.size();
  std::vector<int> result(max + 1);
  for (size_t i=0; i < S.size(); ++i) {
    result[i] = (S[i] == 'I') ? min++: max--;
  }
  result[result.size() - 1] = min;
  return result;
}

int main() {
  std::string input1 = "IDID";
  std::vector<int> expected1 { 0, 4, 1, 3, 2 };
  std::vector<int> result1 = diStringMatch(input1);
  printResult(expected1, result1, input1);

  std::string input2 = "III";
  std::vector<int> expected2 { 0 , 1, 2, 3 };
  std::vector<int> result2 = diStringMatch(input2);
  printResult(expected2, result2, input2);

  std::string input3 = "DDI";
  std::vector<int> expected3 { 3, 2, 0, 1 };
  std::vector<int> result3 = diStringMatch(input3);
  printResult(expected3, result3, input3);

  return 0;
}
