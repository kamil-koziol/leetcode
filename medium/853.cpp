#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      vector<pair<int, float>> cars;
      int n = position.size();
      for(int i=0; i<n; i++) {
        float driveTime = (target - position[i]) / (float) speed[i];
        cars.emplace_back(make_pair(position[i], driveTime));
      }
      // sorts by first (position)
      sort(cars.begin(), cars.end());


      int result = 1;

      for(int i=n-2; i>=0; i--) {
        if(cars[i+1].second >= cars[i].second) {
          cars[i].second = cars[i+1].second;
          continue;
        } else {
          result++;
        }
      }

      return result;
    }
};


int main() {
  Solution s;
  vector<int> position = {3};
  vector<int> speed = {3};
  int target = 10;

  cout << s.carFleet(target, position, speed) << endl;
}

