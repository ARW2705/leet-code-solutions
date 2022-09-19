#include <iostream>
#include <string>

int minPartitions(std::string n) {
  char maxDigit = '1';
  for (char c : n) {
    maxDigit = std::max(maxDigit, c);
  }
  return maxDigit - '0';
}

int main() {
  std::string s1 = "32";
  std::cout << "expected 3, got " << minPartitions(s1) << "\n";

  std::string s2 = "82734";
  std::cout << "expected 8, got " << minPartitions(s2) << "\n";

  std::string s3 = "27346209830709182346";
  std::cout << "expected 9, got " << minPartitions(s3) << "\n";
  
  std::string s4 = "646865316587521321306154643132165454133121654531";
  std::cout << "expected n, got " << minPartitions(s4) << "\n";
  return 0;
}
