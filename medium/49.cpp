#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> store;
        
        for(auto& word: strs) {
          auto counter = getLetterCount(word);
          string hash = getHash(counter);
          store[hash].emplace_back(word);
        }


        vector<vector<string>> result;
        for(auto& kv: store) {
          result.emplace_back(kv.second);
        }

        return result;
    }
private:
    vector<int> getLetterCount(string word) {
      int NO_ASCII_LETTERS = 26;
      vector<int> counter(NO_ASCII_LETTERS);

      for(char& letter: word) {
        counter[letter]++;
      }

      return counter;
    }

    string getHash(vector<int>& arr) {
      string hash = "";

      for(int& num: arr) {
        hash.append(to_string(num) + '#'); 
      }
      return hash;
    }

};
