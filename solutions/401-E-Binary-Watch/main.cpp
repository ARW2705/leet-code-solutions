#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "../../utilities/print-vector.cpp"

std::vector<std::string> readBinaryWatch(int turnedOn) {
  std::unordered_map<int, int> bitMap;
  std::vector<std::string> times;
  int bitCount = 0;
  int intSize = sizeof(int) * 8;
  for (int time = 0; time < 60; ++time) {
    for (int i = 0; i < intSize; ++i) {
      bitCount += ((1 << i) & time) ? 1 : 0;
    }
    bitMap[time] = bitCount;
    bitCount = 0;
  }
  for (int hour = 0; hour < 12; ++hour) {
    for (int minute = 0; minute < 60; ++minute) {
      int combinedCount = bitMap[hour] + bitMap[minute];
      if (combinedCount == turnedOn) {
        times.push_back(std::to_string(hour) + ":" + (minute < 10 ? "0" : "") + std::to_string(minute));
      }
    }
  }
  return times;
}

int main() {
  std::vector<std::string> s1 = readBinaryWatch(1);
  printVector(s1);

  std::vector<std::string> s2 = readBinaryWatch(9);
  printVector(s2);

  return 0;
}
