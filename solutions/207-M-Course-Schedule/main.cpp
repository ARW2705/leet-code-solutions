#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "../../utilities/print-success.cpp"
#include "../../utilities/print-vector.cpp"
#include "../../utilities/print-matrix.cpp"

// int findZeroDegree(std::vector<int>& inDegrees) {
//   for (int i = 0; i < inDegrees.size(); ++i) {
//     if (!inDegrees[i]) {
//       return i;
//     }
//   }
//   return -1;
// }
//
// bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
//   std::vector<int> inDegrees(numCourses, 0);
//   std::vector<std::vector<int>> adjacencyList(numCourses);
//   for (auto prerequisite : prerequisites) {
//     ++inDegrees[prerequisite[1]];
//     adjacencyList[prerequisite[0]].push_back(prerequisite[1]);
//   }
//
//   for (int i = 0; i < numCourses; ++i) {
//     int index = findZeroDegree(inDegrees);
//     if (index == -1) {
//       return false;
//     }
//     for (auto adjacent : adjacencyList[index]) {
//       --inDegrees[adjacent];
//     }
//     inDegrees[index] = -1;
//   }
//
//   return true;
// }


// avoid additional searching by queuing new 0 indegree vertices as they are decremented
bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
  std::vector<int> inDegrees(numCourses, 0);
  std::vector<std::vector<int>> adjacencyList(numCourses);
  for (auto prerequisite : prerequisites) {
    ++inDegrees[prerequisite[1]];
    adjacencyList[prerequisite[0]].push_back(prerequisite[1]);
  }

  std::queue<int> q;
  for (int i = 0; i < inDegrees.size(); ++i) {
    if (!inDegrees[i]) {
      q.push(i);
    }
  }

  for (int i = 0; i < numCourses; ++i) {
    if (q.empty()) {
      return false;
    }
    int index = q.front();
    q.pop();
    for (auto adjacent : adjacencyList[index]) {
      --inDegrees[adjacent];
      if (!inDegrees[adjacent]) {
        q.push(adjacent);
      }
    }
    inDegrees[index] = -1;
  }

  return true;
}


// using dfs and marking visited vertices
// bool detectCycleDFS(int index, std::vector<int>& visited, std::vector<std::vector<int>>& adjacencyList) {
//   if (visited[index] == 2) {
//     return false;
//   } else if (visited[index] == 1) {
//     return true;
//   } else {
//     visited[index] = 1;
//     for (int adjacent : adjacencyList[index]) {
//       if (detectCycleDFS(adjacent, visited, adjacencyList)) {
//         return true;
//       }
//     }
//     visited[index] = 2;
//     return false;
//   }
// }
//
// bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
//   std::vector<std::vector<int>> adjacencyList(numCourses);
//   for (auto prerequisite : prerequisites) {
//     adjacencyList[prerequisite[0]].push_back(prerequisite[1]);
//   }
//
//   std::vector<int> visited(numCourses, 0);
//   for (int i = 0; i < numCourses; ++i) {
//     if (detectCycleDFS(i, visited, adjacencyList)) {
//       return false;
//     }
//   }
//
//   return true;
// }

int main() {
  std::vector<std::vector<int>> m1 {
    { 1, 0 }
  };
  printSuccess(canFinish(2, m1));

  std::vector<std::vector<int>> m2 {
    { 1, 0 },
    { 0, 1 }
  };
  printSuccess(!canFinish(2, m2));

  std::vector<std::vector<int>> m3 {
    { 1, 0 },
    { 2, 1 },
    { 2, 0 }
  };
  printSuccess(canFinish(3, m3));

  std::vector<std::vector<int>> m4 {
    { 1, 0 },
    { 2, 1 },
    { 2, 0 },
    { 1, 2 }
  };
  printSuccess(!canFinish(3, m4));

  std::vector<std::vector<int>> m5 {
    { 1, 0 },
    { 4, 1 },
    { 3, 2 },
    { 2, 0 }
  };
  printSuccess(canFinish(5, m5));

  std::vector<std::vector<int>> m6 {
    { 1, 0 },
    { 4, 1 },
    { 2, 4 },
    { 1, 2 }
  };
  printSuccess(!canFinish(5, m6));

  std::vector<std::vector<int>> m7 {
    { 0, 1 },
    { 3, 1 },
    { 1, 3 },
    { 3, 2 }
  };
  printSuccess(!canFinish(4, m7));

  std::vector<std::vector<int>> m8 {
    { 0, 1 },
    { 1, 3 },
    { 3, 2 },
    { 2, 1 }
  };
  printSuccess(!canFinish(4, m8));

  std::vector<std::vector<int>> m9 {
    { 0,  10 },
    { 3,  18 },
    { 5,  5  },
    { 6,  11 },
    { 11, 14 },
    { 13, 1  },
    { 15, 1  },
    { 17, 4  }
  };
  printSuccess(!canFinish(20, m9));
  return 0;
}
