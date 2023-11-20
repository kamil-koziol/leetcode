#include <cstdlib>
#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> s;

    int result = 0;
    for (string &token : tokens) {
      if (isOperator(token)) {
        int num1 = s.top();
        s.pop();
        int num2 = s.top();
        s.pop();
        int eval = evalOperation(num1, num2, token);
        s.push(eval);
      } else {
        s.push(stoi(token));
      }
    }

    return s.top();
  }

private:
  string ops[4] = {"+", "-", "*", "/"};
  bool isOperator(string op) {
    for (auto &c : ops) {
      if (c == op)
        return true;
    }
    return false;
  }

  int evalOperation(int num1, int num2, string op) {

    if (op == "+") {
      return num2 + num1;
    } else if (op == "-") {
      return num2 - num1;
    } else if (op == "/") {
      return num2 / num1;
    } else if (op == "*") {
      return num2 * num1;
    }

    return 0;
  }
};


int main() {
  Solution s;

  vector<string> tokens = {"2", "1", "+", "3", "*"};
  cout << s.evalRPN(tokens) << endl;
}
