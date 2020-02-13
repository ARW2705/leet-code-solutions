#include <iostream>
#include <vector>

void printResult(std::vector<int>& v, int n) {
  std::cout << "For n = " << n << " generated [";

  for (size_t i=0; i < v.size(); ++i) {
    std::cout << v[i];
    if (i < v.size() - 1) {
      std::cout << ", ";
    }
  }

  std::cout << "]\n";
}

std::vector<int> sumZero(int n) {
  std::vector<int> result;
  result.reserve(n);
  if (n % 2 == 1) {
    result.push_back(0);
  }
  int elems = n / 2 + 1;
  for (size_t i=1; i < elems; ++i) {
    result.push_back(i);
    result.push_back(-i);
  }
  return result;
}

int main() {
  std::vector<int> result1 = sumZero(5);
  printResult(result1, 5);

  std::vector<int> result2 = sumZero(3);
  printResult(result2, 3);

  std::vector<int> result3 = sumZero(1);
  printResult(result3, 1);
  return 0;
}
