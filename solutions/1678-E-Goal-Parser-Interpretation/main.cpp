#include <iostream>
#include <string>
#include "../../utilities/print-success.cpp"

std::string interpret(std::string command) {
  std::string interpreted = "";
  for (int i = 0; i < command.size(); ++i) {
    if (command[i] == 'G') {
      interpreted += 'G';
    } else if (command[i + 1] == ')') {
      interpreted += 'o';
      ++i;
    } else {
      interpreted += "al";
      i += 3;
    }
  }
  return interpreted;
}

int main() {
  std::string s1 = "G()(al)";
  printSuccess(interpret(s1) == "Goal");

  std::string s2 = "G()()()()(al)";
  printSuccess(interpret(s2) == "Gooooal");

  std::string s3 = "(al)G(al)()()G";
  printSuccess(interpret(s3) == "alGalooG");

  return 0;
}
