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

class Compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        ListNode* tail=NULL;

        priority_queue<ListNode*,vector<ListNode*>,Compare> minheap;

        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                minheap.push(lists[i]);
            }
        }

        while(!minheap.empty()){
            ListNode* temp = minheap.top();
            minheap.pop();
            if(head==NULL){
                head=temp;
                tail=temp;
            }
            else{
                tail->next=temp;
                tail=temp;
            }
            if(temp->next!=NULL){
                minheap.push(temp->next);
            }
        }

        return head;
    }
};