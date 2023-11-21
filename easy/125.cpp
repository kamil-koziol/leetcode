#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

      string ns = "";

      for(const char& c: s) {
        if(!isalnum(c)) continue;

        ns.push_back(tolower(c));
      }
      int l = 0;
      int r = ns.size() - 1;
      

      while(l <= r) {
        if(ns[l] != ns[r]) return false;
        l++;
        r--;
      }

      return true;
    }
};


int main() {
  Solution s;
  cout << s.isPalindrome("Race1 car") << endl;
}
