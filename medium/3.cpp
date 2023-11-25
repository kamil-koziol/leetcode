#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = 256;
        int chars[N];
        for(int i=0; i<N; i++) { chars[i] = -1; }

        int longest = 0;

        int current = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int charIdx = c;

            if (chars[charIdx] != -1) {
                int len = i - current;
                longest = max(len, longest);

                for(int j=0; j<N; j++) {
                    if(chars[j] < chars[charIdx]) {
                        chars[j] = -1;
                    }
                }
                current = chars[charIdx]+1;
                chars[charIdx] = i;
                continue;
            }

            chars[charIdx] = i;
        }

        int len = s.size() - current;
        longest = max(longest, len);

        return longest;
    }
};


int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("au") << endl;
    cout << s.lengthOfLongestSubstring("") << endl;
    cout << s.lengthOfLongestSubstring(" ") << endl;
    cout << s.lengthOfLongestSubstring("abba") << endl;
}
