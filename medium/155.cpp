#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class MinStack {
private:
    stack<int> values;
    stack<int> mins;
public:
    MinStack() {
      values = stack<int>();
      mins = stack<int>();
    }
    
    void push(int val) {
      if(mins.empty() || val <= mins.top()) {
        mins.push(val);
      }

      values.push(val);
    }
    
    void pop() {
      int popped = values.top();
      values.pop();

      if(popped == mins.top()) {
        mins.pop();
      }
    }
    
    int top() {
      return values.top();
    }
    
    int getMin() {
      return mins.top(); 
    }
};


int main() {
  MinStack ms = MinStack();
  ms.push(2);
  ms.push(1);
  ms.push(3);
  ms.pop();
  ms.pop();
  ms.push(4);

  cout << ms.top() << " " << ms.getMin() << endl;
}
