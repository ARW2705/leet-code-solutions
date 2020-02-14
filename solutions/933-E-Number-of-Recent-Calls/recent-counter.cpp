#include "recent-counter.hpp"

RecentCounter::RecentCounter() {
  pingsPtr = new std::vector<int>();
}

RecentCounter::~RecentCounter() {
  delete pingsPtr;
  pingsPtr = nullptr;
}


int RecentCounter::ping(int t) {
  pingsPtr->push_back(t);
  int pingCount = 0;
  for (int i=pingsPtr->size() - 1; i >=0; --i) {
    if (t - pingsPtr->at(i) <= 3000) {
      ++pingCount;
    } else {
      break;
    }
  }
  return pingCount;
}
