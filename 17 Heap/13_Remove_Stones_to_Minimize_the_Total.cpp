class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        //piles = {5,4,9}  * k   floor(pile / 2)
        priority_queue<int> maxheap;
        for(int i=0;i<piles.size();i++){
            maxheap.push(piles[i]);
        }
        while(k--){
            int pile = maxheap.top();
            maxheap.pop();
            pile = pile - floor(pile/2);
            maxheap.push(pile); 
        }

        int ans = 0;
        while(!maxheap.empty()){
            int temp= maxheap.top();
            maxheap.pop();
            ans = ans + temp;
        }

        return ans;
        
    }
};