#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  char separator = ';';
  char special = '\\';
  /*
   * @param strs: a list of strings
   * @return: encodes a list of strings to a single string.
   */
  string encode(vector<string> &strs) {
    string result = "";

    // split by char separator

    for (string &word : strs) {
      string nword = "";

      for (char &letter : word) {
        string newLetter;

        if (letter == separator) {
          newLetter.push_back(special);
          newLetter.push_back(separator);
        }

        else if (letter == special) {
          newLetter.push_back(special);
          newLetter.push_back(special);
        }

        else {
          newLetter = letter;
        }

        nword.append(newLetter);
      }

      nword.append(string(1, separator));
      result.append(nword);
    }

    // to avoid last_separation
    result.pop_back();

    return result;
  }

  /*
   * @param str: A string
   * @return: decodes a single string to a list of strings
   */
  vector<string> decode(string &str) {
    // write your code here
    vector<string> words;
    string word = "";

    for (int i = 0; i < str.size(); i++) {
      char letter = str[i];

      if (letter == special) {
        if (i + 1 >= str.size())
          continue;

        char nextLetter = str[i + 1];
        i++;

        word.push_back(nextLetter);
      }

      else if (letter == separator) {
        words.emplace_back(word);
        word = "";
      }

      else {
        word.push_back(letter);
      }
    }

    words.emplace_back(word);

    return words;
  }
};

int main() {
  Solution s;
  vector<string> v = {";;\\ab;c", "ad\\;;;;\\\\c", "chsuj\\;"};
  string encoded = s.encode(v);
  cout << encoded << endl;

  for (auto &w : s.decode(encoded)) {
    cout << w << endl;
  }
}
