class Solution {
public:
    void set(vector<vector<int>>& matrix,int i,int j,int& m,int& n) {
        int pos=i;
        while(pos>=0){
            matrix[pos][j]=0;
            pos--;
        }
        pos=j;
        while(pos>=0){
            matrix[i][pos]=0;
            pos--;
        }
        pos=i;
        while(pos<m){
            matrix[pos][j]=0;
            pos++;
        }
        pos=j;
        while(pos<n){
            matrix[i][pos]=0;
            pos++;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
      int m= matrix.size();
      int n= matrix[0].size();
      vector<pair<int,int>> pos; 
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                pair<int,int> temp;
                temp.first=i;
                temp.second=j;
                pos.push_back(temp);
            }
        }
      }
      for(int z=0;z<pos.size();z++){
          set(matrix,pos[z].first,pos[z].second,m,n);
      }
    }
};