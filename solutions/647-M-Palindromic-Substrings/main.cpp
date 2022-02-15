#include <iostream>
#include <string>
#include <vector>
#include "../../utilities/print-success.cpp"

int countSubstrings(std::string s) {
  int size = s.size();
  int count = 0;
  int leftWall, rightWall, diff;
  for (int i = 0; i < size; ++i) {
    leftWall = i - 1;
    rightWall = i;

    while (rightWall < size - 1 && s[rightWall] == s[rightWall + 1]) {
      ++rightWall;
    }

    diff = rightWall - leftWall;
    count += (diff * (diff + 1)) / 2;
    i = rightWall;
    ++rightWall;

    while (leftWall >= 0 && rightWall < size && s[leftWall] == s[rightWall]) {
      ++rightWall;
      --leftWall;
      ++count;
    }
  }
  return count;
}

int main() {
  std::string s1 = "abc";
  printSuccess(countSubstrings(s1) == 3);

  std::string s2 = "aaa";
  printSuccess(countSubstrings(s2) == 6);

  std::string s3 = "aabcc";
  printSuccess(countSubstrings(s3) == 7);

  std::string s4 = "aabbbcccc";
  printSuccess(countSubstrings(s4) == 19);

  std::string s5 = "aliuhblawekjfahglshgkasdkfhldksfdshahfdsadsffdsasdf";
  printSuccess(countSubstrings(s5) == 56);

  std::string s6 = "hah";
  printSuccess(countSubstrings(s6) == 4);
  return 0;
}
