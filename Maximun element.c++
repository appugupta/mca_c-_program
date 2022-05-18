#include <iostream>

using namespace std;

struct stack {
  struct s_node {
    int value;
    int max_value;
    s_node *prev;
  };

  s_node *top = nullptr;

  void push(int value) {
    top = new s_node { value, top ? max(top->max_value, value) : value, top };
  }

  void pop() {
    if (top)
      top = top->prev;
  }

  int max_value() {
    if (!top)
      throw exception();
    return top->max_value;
  }
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  stack s;
  int n; cin >> n;
  while (n--) {
    int o; cin >> o;
    switch (o) {
      case 1: {
        int v; cin >> v;
        s.push(v);
      }
      break;
      case 2:
      s.pop();
      break;
      case 3:
      cout << s.max_value() << '\n';
      break;
    }
  }
  return 0;
}