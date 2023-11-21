#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int largest = 0;
      int l = 0;
      int r = height.size()-1;
      
      while(l < r) {

        int h = min(height[l], height[r]);
        int w = r - l;
        int area = w * h;

        largest = max(area, largest);

        // we move smaller because its already max possible height for that bar
        if(height[l] < height[r]) {
          l++;
        } else {
          r--;
        }
      }

      return largest;
    }
};

int main() {
  Solution s;
  vector<int> v = {1,8,6,2,5,3,8,3,7,1,3};
  cout << s.maxArea(v) << endl;
}
