public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
         
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(M[a][b]){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int mightceleb = st.top();
        st.pop();
        
        for(int i=0;i<n;i++){
            if(M[mightceleb][i]){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if(M[i][mightceleb]!=1 && i!=mightceleb){
                return -1;
            }
        }
        return mightceleb;
    }