#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    const int n = 9;

    bool columnCheck[n][n] = {false};
    bool boxCheck[n][n] = {false};
    bool rowCheck[n][n] = {false};

    for (int y = 0; y < n; y++) {
      // row
      for (int x = 0; x < n; x++) {
        // column
        char c = board[y][x];
        if (c == '.')
          continue;

        int num = c - '0';

        if (rowCheck[y][num-1] == true) {
          return false;
        }

        rowCheck[y][num-1] = true;

        // handle column

        if(columnCheck[x][num-1] == true) {
          return false;
        }

        columnCheck[x][num-1] = true;

        // handle box
        int boxX = x / 3;
        int boxY = y / 3;

        int boxIdx = boxY * (n/3) + boxX;

        if(boxCheck[boxIdx][num-1] == true) {
          return false;
        }

        boxCheck[boxIdx][num-1] = true;
      }
    }

    return true;
  }
};


int main() {

}
