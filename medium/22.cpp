#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate(n, result, 0, 0, "");
    return result;
  }

private:
  void generate(int n, vector<string>& result, int opened, int closed, string c) {
    if(opened == n && closed == n) {
      result.emplace_back(c);
      return;
    }      

    if(opened < n) {
      generate(n, result, opened+1, closed, c + "(");
    } 

    if(closed < opened) {
      generate(n, result, opened, closed+1, c + ")");
    }

  }
};

int main() {
  Solution s;
  auto par = s.generateParenthesis(3);
  for (auto &a : par) {
    cout << a << endl;
  }
  cout << par.size() << endl;
}
