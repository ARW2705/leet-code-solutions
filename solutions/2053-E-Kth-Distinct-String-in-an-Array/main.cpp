#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../../utilities/print-success.cpp"


std::string kthDistinct(std::vector<std::string>& arr, int k) {
  std::unordered_map<std::string, int> previous;
  for (auto str : arr) {
    ++previous[str];
  }
  std::cout << previous.size() << "\n";
  if (k <= previous.size()) {
    for (auto str : arr) {
      if (previous[str] == 1) {
        std::cout << str << "\n";
        --k;
      }
      if (!k) return str;
    }
  }
  return "";
}

int main() {
  std::vector<std::string> v1 {"d","b","c","b","c","a"};
  std::string r1 = kthDistinct(v1, 2);
  std::cout << r1 << "\n";
  printSuccess(r1.compare("a") == 0);

  std::vector<std::string> v2 {"aaa", "aa", "a"};
  std::string r2 = kthDistinct(v2, 1);
  std::cout << r2 << "\n";
  printSuccess(r2.compare("aaa") == 0);

  std::vector<std::string> v3 {"a", "b", "a"};
  std::string r3 = kthDistinct(v3, 3);
  std::cout << r3 << "\n";
  printSuccess(r3.compare("") == 0);

  std::vector<std::string> v4 {"c","exjk","nbmg","kgnas","s","oydx","ghpao","c","r","ohdm","fq","ashgg","mm","cc","mymy","w","t","neb","grjdb","cukk","ujyhn","dq","hhuo","qu","seslw","ybulz","iug","rs","kyfu","krz","nw","txnn","r","zpuao","sh","rfc","c","hgr","jfia","egm","gmuuv","gh","x","nfvgv","ibo","al","wn","o","dyu","zgkk","gdzrf","m","ui","xwsj","zeld","muowr","d","xgiu","yfu"};
  std::string r4 = kthDistinct(v4, 19);
  std::cout << r4 << "\n";
  printSuccess(r4.compare("dq") == 0);

  return 0;
}
