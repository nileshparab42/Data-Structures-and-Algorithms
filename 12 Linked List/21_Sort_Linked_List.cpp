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
    ListNode* sortList(ListNode* head) {
        vector<int> list;
        ListNode* temp=head;
        while(temp!=NULL){
            list.push_back(temp->val);
            temp=temp->next;
        }
        sort(list.begin(),list.end());
        temp=head;
        int count=0;
        while(temp!=NULL){
            temp->val=list[count];
            count++;
            temp=temp->next;
        }
        return head;
    }
};