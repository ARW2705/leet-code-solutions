#include "node.hpp"

Node::Node(int _val) {
  val = _val;
}

Node::Node(int _val, std::vector<Node*> _children) {
  val = _val;
  children = _children;
}
