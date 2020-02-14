#ifndef _recent_counter_hpp
#define _recent_counter_hpp

#include <vector>

class RecentCounter {
 public:
  RecentCounter();
  ~RecentCounter();

  int ping(int t);

 private:
  std::vector<int>* pingsPtr;
};

#endif
