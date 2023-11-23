#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size();
       int n = matrix[0].size();

       int l = 0; 
       int u = m-1;

       while(l <= u) {
         int mid = (l+u)/2;
         if(matrix[mid][0] == target) {
           return true;
         }

         else if(target < matrix[mid][0]) {
           u = mid-1;
         }

         else if(target > matrix[mid][0]) {
           l = mid+1;
         }
       }

       int row = (l+u)/2;
       l = 0; 
       int r = n-1;

       while(l <= r) {
         int mid = (l+r)/2;
         if(matrix[row][mid] == target) {
           return true;
         }

         else if(target < matrix[row][mid]) {
           r = mid-1;
         }

         else if(target > matrix[row][mid]) {
           l = mid+1;
         }
       }
       return false;
    }
};
