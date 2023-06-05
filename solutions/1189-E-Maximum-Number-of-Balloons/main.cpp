#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../../utilities/print-success.cpp"

using namespace std;

int maxNumberOfBalloons(string text) {
  vector<int> balloon(5);
  for (char c : text) {
    if      (c == 'a') ++balloon[0];
    else if (c == 'b') ++balloon[1];
    else if (c == 'l') ++balloon[2];
    else if (c == 'n') ++balloon[3];
    else if (c == 'o') ++balloon[4];
  }

  balloon[2] /= 2;
  balloon[4] /= 2;
  return *min_element(balloon.begin(), balloon.end());
}

int main() {
  string s1 = "nlaebolko";
  printSuccess(maxNumberOfBalloons(s1) == 1);

  string s2 = "loonbalxballpoon";
  printSuccess(maxNumberOfBalloons(s2) == 2);

  string s3 = "leetcode";
  printSuccess(maxNumberOfBalloons(s3) == 0);

  return 0;
}
