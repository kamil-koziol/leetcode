#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    // height, idx
    stack<pair<int, int>> stk;
    int largest = 0;

    stk.push({heights[0], 0});

    int n = heights.size();
    for(int i=1; i<n; i++) {
      int num = heights[i];

      int start = i;
      if(heights[i]<heights[i-1]) {
        while(!stk.empty() && num < stk.top().first) {
          start = stk.top().second;
          auto stktop = stk.top();
          int areaExpanded = (i-stktop.second) * stktop.first;
          largest = max(largest, areaExpanded);
          stk.pop();
        }

        stk.push({num, start});
      }

      else {
        stk.push({num, i});
      }
    }

    while(!stk.empty()) {
      auto val = stk.top();
      int area = (n - val.second)*val.first;
      largest = max(largest, area);
      stk.pop();
    }

    return largest;
  }
};

int main() {
  Solution s;
  vector<int> heights = {3,6,5,7,4,8,1,0};
  cout << s.largestRectangleArea(heights) << endl;
}
