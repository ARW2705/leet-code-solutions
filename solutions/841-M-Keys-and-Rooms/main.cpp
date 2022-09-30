#include <iostream>
#include <vector>
#include <queue>
#include "../../utilities/print-success.cpp"

bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
  std::vector<bool> visited(rooms.size(), false);
  std::queue<int> q;
  q.push(0);
  
  while (!q.empty()) {
    int room = q.front();
    visited[room] = true;
    q.pop();
    for (int key : rooms[room]) {
      if (!visited[key]) q.push(key);
    }
  }

  for (bool v : visited) {
    if (!v) return false;
  }
  return true;
}

int main() {
  std::vector<std::vector<int>> r1 { {1}, {2}, {3}, {} };
  printSuccess(canVisitAllRooms(r1));

  std::vector<std::vector<int>> r2 { {1,3}, {3,0,1}, {2}, {0} };
  printSuccess(!canVisitAllRooms(r2));

  return 0;
}
