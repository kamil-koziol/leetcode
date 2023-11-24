#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int l = 0;
    int r = 1;
    int n = prices.size();

    int minl = prices[l];
    int maxr = prices[r];
    int result = 0;

    while (r < n) {
      if (prices[r] < minl) {
        minl = prices[r];
        l = r;
        r++;

      } else {
        int diff = prices[r] - prices[l];
        result = max(result, diff);
        r++;
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> v = {7, 1, 5, 3, 6, 4};
  cout << s.maxProfit(v) << endl;
}
