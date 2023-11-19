#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int n = nums.size();

      unordered_map<int, int> counter;

      for(int &num: nums) {
        counter[num]++;
      }

      vector<vector<int>> buckets(n+1);
      for(auto &kv: counter) {
        buckets[kv.second].push_back(kv.first);
      }

      vector<int> result;

      for(int i=n; i>=0; i--) {
        if(buckets.empty()) continue;
        if(result.size() >= k) break;

        result.insert(result.end(), buckets[i].begin(), buckets[i].end());
      }


      return result;
    }
};


int main() {
  Solution s;
  vector<int> v = {1,2,3,4,1,2,2,3,3,3,3};

  vector<int> result =  s.topKFrequent(v, 3);
  for(int &num: result) {
    cout << num << endl;
  }
}
