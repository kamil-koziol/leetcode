#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> open;
    unordered_map<char, char> parens = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    for (auto &c : s) {
      bool closing_bracket = parens.find(c) == parens.end();
      if (closing_bracket) {
        if (open.empty()) {
          return false;
        }

        if (open.top() != parens[c]) {
          return false;
        }

        open.pop();
      } else {
        open.push(c);
      }
    }

    return open.empty();
  }
};

int main() {
  Solution s;

  cout << s.isValid("()") << endl;
  cout << s.isValid("()[]{}") << endl;
  cout << s.isValid("(]") << endl;
}
