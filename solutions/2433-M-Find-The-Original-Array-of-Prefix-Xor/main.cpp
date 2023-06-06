#include <iostream>
#include <vector>
#include "../../utilities/compare-vectors.cpp"
#include "../../utilities/print-vector.cpp"
#include "../../utilities/print-success.cpp"

using namespace std;

vector<int> findArray(vector<int>& pref) {
  vector<int> arr(pref.size());
  arr[0] = pref[0];
  for (int i = 1; i < pref.size(); ++i) {
    arr[i] = pref[i - 1] ^ pref[i];
  }

  return arr;
}

int main() {
  vector<int> p1 { 5, 2, 0, 3, 1 };
  vector<int> e1 { 5, 7, 2, 3, 2 };
  vector<int> r1 = findArray(p1);
  printVector(r1);
  printSuccess(compareVector(r1, e1));

  return 0;
}
