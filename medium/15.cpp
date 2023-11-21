#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i != 0 && nums[i - 1] == nums[i])
        continue;

      // two-sum here

      int target = 0 - nums[i];

      int l = i+1;
      int r = n - 1;

      while (l < r) {
        int total = nums[l] + nums[r];
        if (total == target) {
          vector<int> triplet = {nums[i], nums[l], nums[r]};
          result.emplace_back(triplet);
          l++;
          while(nums[l-1] == nums[l] && l < r) {
            l++;
          }
        } else if (total < target) {
          l++;
          while(nums[l-1] == nums[l] && l < r) {
            l++;
          }
        } else if (total > target) {
          r--;
          while(nums[r+1] == nums[r] && l < r) {
            r--;
          }
        }
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  // -4 -1 -1 0 1 2
  vector<int> nums = {-1,0,1,2,-1,-4};
  auto result = s.threeSum(nums);

  for (auto &v : result) {
    cout << "[" << v[0] << "," << v[1] << "," << v[2] << "]"
         << " ";
  }
}
