#include <iostream>

int subtractProductAndSum(int n) {
  int product = 1;
  int sum = 0;
  int mod;
  while (n > 0) {
    mod = n % 10;
    product *= mod;
    sum += mod;
    n /= 10;
  }
  return product - sum;
}

int main() {
  std::cout << "Ex1: " << subtractProductAndSum(234) << "\n";
  std::cout << "Ex2: " << subtractProductAndSum(4421) << "\n";
  return 0;
}
