#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      vector<int> result(n, 0);
      stack<pair<int,int>> stk;

      for(int i=0; i<n; i++) {
        int ct = temperatures[i];

        if(stk.empty()) {
          stk.push(make_pair(ct, i));
          continue;
        }

        while(ct > stk.top().first) {
          auto r = stk.top();
          stk.pop();

          int daysPassed = i - r.second;
          result[r.second] = daysPassed;

          if(stk.empty()) break;
        } 

        if(stk.empty() || ct <= stk.top().first) {
          stk.push(make_pair(ct, i));
        }
      }

      return result;
    }
};


int main() {
  Solution s;
  vector<int> temperatures = {73,74,75,71,69,72,76,73};
  auto result = s.dailyTemperatures(temperatures);

  for(auto& num: result) {
    cout << num << ", ";
  }
}
