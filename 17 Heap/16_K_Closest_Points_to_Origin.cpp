class Pointswithdist{
    public:
    pair<int,int> point;
    float dist;
    Pointswithdist(){}
    Pointswithdist(vector<int> nums){
        point.first=nums[0];
        point.second=nums[1];
        dist=sqrt((pow(nums[0],2))+(pow(nums[1],2)));
    }
};
class Compare{
    public:
    bool operator()(Pointswithdist* a,Pointswithdist* b){
        return a->dist > b->dist;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<Pointswithdist*,vector<Pointswithdist*>,Compare> minheap;
        for(int i=0;i<points.size();i++){
            Pointswithdist* temp = new Pointswithdist(points[i]);
            minheap.push(temp);
        }
        while(k--){
            Pointswithdist* temp = minheap.top();
            vector<int> op;
            pair<int,int> numbers = temp->point;
            op.push_back(numbers.first);
            op.push_back(numbers.second);
            ans.push_back(op);
            cout<<temp->dist;
            minheap.pop();            
        }
        while(!minheap.empty()){
            Pointswithdist* temp = minheap.top();
            cout<<temp->dist;
            minheap.pop();
        }
        return ans;
    }
};