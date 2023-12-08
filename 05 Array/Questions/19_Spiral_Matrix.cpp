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

//Practice
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
          vector<int> ans;
          int m=matrix.size();
          int n=matrix[0].size();
          int z=m*n;
          int ht=0;
          int vr=n-1;
          int hb=m-1;
          int vl=0;

          while(z>0){
              cout<<"z="<<z<<endl;
              for(int i=vl;i<=vr&&z>0;i++){
                  ans.push_back(matrix[ht][i]);
                  z--;
              }
              ht++;
              for(int i=ht;i<=hb&&z>0;i++){
                  ans.push_back(matrix[i][vr]);
                  z--;
              }
              vr--;
              for(int i=vr;i>=vl&&z>0;i--){
                  ans.push_back(matrix[hb][i]);
                  z--;
              }
              hb--;
              for(int i=hb;i>=ht&&z>0;i--){
                  ans.push_back(matrix[i][vl]);
                  z--;
              }
              vl++;
          }
          return ans;
    }
};