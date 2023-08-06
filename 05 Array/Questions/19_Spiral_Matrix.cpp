class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
          int top=0;
          int right=matrix[0].size()-1;
          int bottom=matrix.size()-1;
          int left=0;

          int n=(matrix[0].size()) * (matrix.size());
          vector<int> ans;

          while(n>0){

              for(int i=left;i<=right&&n>0;i++){
                  ans.push_back(matrix[top][i]);
                  n--;
              }
              top++;

              for(int i=top;i<=bottom&&n>0;i++){
                  ans.push_back(matrix[i][right]);
                  n--;
              }
              right--;

              for(int i=right;i>=left&&n>0;i--){
                  ans.push_back(matrix[bottom][i]);
                  n--;
              }
              bottom--;

              for(int i=bottom;i>=top&&n>0;i--){
                  ans.push_back(matrix[i][left]);
                  n--;
              }
              left++;
          }
          return ans;
    }
};