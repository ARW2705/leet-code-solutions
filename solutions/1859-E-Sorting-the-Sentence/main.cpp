#include <iostream>
#include <string>
#include <map>
#include "../../utilities/print-success.cpp"

std::string sortSentence(std::string s) {
  std::map<char, std::string> ordered;
  std::string tmp = "";
  for (char c : s) {
    if (c >= '0' && c <= '9') {
      ordered.insert(std::make_pair(c, tmp));
      tmp = "";
    } else if (c != ' ') {
      tmp += c;
    }
  }

  std::string sorted = "";
  std::map<char, std::string>::iterator iter;
  for (iter = ordered.begin(); iter != ordered.end(); ++iter) {
    if (sorted.size() > 0) {
      sorted += " ";
    }
    sorted += iter->second;
  }

  return sorted;
}

int main() {
  std::string s1 = "is2 sentence4 This1 a3";
  std::string e1 = "This is a sentence";
  std::string r1 = sortSentence(s1);
  printSuccess(r1.compare(e1) == 0);

  std::string s2 = "Myself2 Me1 I4 and3";
  std::string e2 = "Me Myself and I";
  std::string r2 = sortSentence(s2);
  printSuccess(r2.compare(e2) == 0);

  return 0;
}
