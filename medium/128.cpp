#include "vector"
#include "string"
#include "unordered_set";

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> m(nums.begin(), nums.end());

      int longest = 0;

      for(auto& num: m) {
        int len = 1;

        if(m.count(num-1)) continue;

        while(m.count(num + len)) {
          len++;
        }

        longest = max(longest, len);
      } 


    return longest;
    }
};

int main() {
  Solution s;


}
