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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* evenhead= new ListNode(-1);
        ListNode* eventail= evenhead;
        ListNode* oddhead= new ListNode(-1);
        ListNode* oddtail= oddhead;
        int it=1;
        ListNode* temp=head;
        while(temp!=NULL){
            if(it%2==0){
                eventail->next=temp;
                eventail=temp;
                temp=temp->next;
                eventail->next=NULL;
            }
            else{
                oddtail->next=temp;
                oddtail=temp;
                temp=temp->next;
                oddtail->next=NULL;
            }
            it++;
        }
        cout<<oddtail->val<<"\n";
        cout<<evenhead->next->val<<"\n";
        if(evenhead->next!=NULL){
            oddtail->next=evenhead->next;
        }
        oddhead=oddhead->next;

        return oddhead;
        
    }
};