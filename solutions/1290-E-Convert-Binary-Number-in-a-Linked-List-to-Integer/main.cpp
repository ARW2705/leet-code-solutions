#include <iostream>

struct Node {
  int key;
  Node* next;

  Node(int _key) {
    key = _key;
    next = nullptr;
  }
};

Node* constructList(int* bits, int size) {
  Node* head = nullptr;
  for (int i=size - 1; i >= 0; --i) {
    if (head == nullptr) {
      head = new Node(bits[i]);
    } else {
      Node* tmp = head;
      head = new Node(bits[i]);
      head->next = tmp;
    }
  }
  return head;
}

int getDecimalValue(Node* head) {
  int result = 0;
  while (head != nullptr) {
    result = (result << 1) + head->key;
    head = head->next;
  }
  return result;
}

int main() {
  int ex1Arr[] = { 1, 0, 1 };
  Node* ex1 = constructList(ex1Arr, 3);
  int result1 = getDecimalValue(ex1);
  std::cout << result1 << " " << (result1 == 5 ? "PASS": "FAIL") << "\n";

  int ex2Arr[] = { 0 };
  Node* ex2 = constructList(ex2Arr, 1);
  int result2 = getDecimalValue(ex2);
  std::cout << result2 << " " << (result2 == 0 ? "PASS": "FAIL") << "\n";

  int ex3Arr[] = { 1 };
  Node* ex3 = constructList(ex3Arr, 1);
  int result3 = getDecimalValue(ex3);
  std::cout << result3 << " " << (result3 == 1 ? "PASS": "FAIL") << "\n";

  int ex4Arr[] = { 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 };
  Node* ex4 = constructList(ex4Arr, 15);
  int result4 = getDecimalValue(ex4);
  std::cout << result4 << " " << (result4 == 18880 ? "PASS": "FAIL") << "\n";

  int ex5Arr[] = { 0, 0 };
  Node* ex5 = constructList(ex5Arr, 2);
  int result5 = getDecimalValue(ex5);
  std::cout << result5 << " " << (result5 == 0 ? "PASS": "FAIL") << "\n";

  return 0;
}
