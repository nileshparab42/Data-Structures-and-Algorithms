class solution{
    public:
    int findPairs(long long a[], long long n)
    {
        //code here.
        unordered_map<int,bool> mapping;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=a[i]+a[j];
                if(mapping.find(sum)!=mapping.end()){
                    return 1;
                }
                else{
                    mapping[sum]=true;
                }
            }
        }
        return 0;
    }
}