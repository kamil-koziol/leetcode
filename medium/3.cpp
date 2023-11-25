#include <ios>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    const int N = 256;
    bool chars[N] = {false};
    int longest = 0;

    int currentLenght = 0;
    for (auto &c : s) {
      int charIdx = c - 'a';

      if (chars[charIdx]) {
        longest = max(longest, currentLenght);

        for (int i = 0; i < N; i++) {
          chars[i] = false;
        }

        currentLenght = 1;
        chars[charIdx] = true;
        continue;
      }

      chars[charIdx] = true;
      currentLenght++;
    }

    longest = max(longest, currentLenght);

    return longest;
  }
};

int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << s.lengthOfLongestSubstring("bbbbb") << endl;
  cout << s.lengthOfLongestSubstring("pwwkewabc") << endl;
}
