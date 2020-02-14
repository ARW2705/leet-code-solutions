#include <iostream>

#include "recent-counter.hpp"

int main() {
  RecentCounter* rc = new RecentCounter();
  int ping1 = rc->ping(1);
  int ping2 = rc->ping(100);
  int ping3 = rc->ping(3001);
  int ping4 = rc->ping(3002);

  std::cout
    << ping1
    << ", "
    << ping2
    << ", "
    << ping3
    << ", "
    << ping4
    << "\n";

  return 0;
}
