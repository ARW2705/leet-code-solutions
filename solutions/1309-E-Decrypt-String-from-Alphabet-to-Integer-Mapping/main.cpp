#include <iostream>
#include <string>

void print(std::string got, std::string expected) {
  std::cout << "Got " << got << ", expected " << expected << " : " << (got == expected ? "PASS": "FAIL") << "\n";
}

std::string freqAlphabets(std::string s) {
  std::string result = "";
  int size = s.size();
  int i = 0;
  for (; i < size ;) {
    if (i < size - 2 && s[i + 2] == '#') {
      result.push_back(static_cast<char>(std::stoi(s.substr(i, 2)) + 'a' - 1));
      i += 3;
    } else {
      result.push_back(static_cast<char>(s[i] - '0' + 'a' - 1));
      ++i;
    }
  }
  return result;
}

int main() {
  std::string s1 = "10#11#12";
  std::string expected1 = "jkab";
  print(freqAlphabets(s1), expected1);

  std::string s2 = "1326#";
  std::string expected2 = "acz";
  print(freqAlphabets(s2), expected2);

  std::string s3 = "25#";
  std::string expected3 = "y";
  print(freqAlphabets(s3), expected3);

  std::string s4 = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";
  std::string expected4 = "abcdefghijklmnopqrstuvwxyz";
  print(freqAlphabets(s4), expected4);
  return 0;
}
