class Compare{
public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> maxheap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            fq[nums[i]]++;
        }
        for(auto i:fq){
            maxheap.push(i);
        }
        while(k--){
            pair<int,int> temp = maxheap.top();
            ans.push_back(temp.first);
            maxheap.pop();
        }
        return ans;
    }
};