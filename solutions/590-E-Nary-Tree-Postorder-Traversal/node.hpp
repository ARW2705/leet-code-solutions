#ifndef _node_hpp
#define _node_hpp

#include <vector>

class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {};
  Node(int _val);
  Node(int _val, std::vector<Node*> _children);
};

#endif
