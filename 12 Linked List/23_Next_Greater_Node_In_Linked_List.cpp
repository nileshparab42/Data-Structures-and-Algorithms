/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        ListNode* temp=head;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        } 
        vector<int> ans=nums;
        stack<int> st;
        st.push(INT_MAX);
        for(int i=nums.size()-1;i>=0;i--){
            if(st.top()<=nums[i]){
                while(st.top()<=nums[i]){
                    st.pop();
                }
                ans[i]=st.top();
                st.push(nums[i]);
            }
            else{
                ans[i]=st.top();
                st.push(nums[i]);
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX){
                ans[i]=0;
            }
        }
        return ans;
    }
};