#include <iostream>
#include <string>

bool judgeCircle(std::string moves) {
  int xPos = 0, yPos = 0;
  for (char move : moves) {
    if (move == 'L') {
      --xPos;
    } else if (move == 'R') {
      ++xPos;
    } else if (move == 'D') {
      --yPos;
    } else {
      ++yPos;
    }
  }
  return xPos == 0 && yPos == 0;
}

int main() {
  std::string test1 = "UD";
  bool atOrigin1 = judgeCircle(test1);
  std::cout << (atOrigin1 ? "Returned to origin": "Not at origin") << "\n" << (atOrigin1 ? "PASS": "FAIL") << "\n";

  std::string test2 = "LL";
  bool atOrigin2 = judgeCircle(test2);
  std::cout << (atOrigin2 ? "Returned to origin": "Not at origin") << "\n" << (atOrigin2 ? "FAIL": "PASS") << "\n";

  return 0;
}
