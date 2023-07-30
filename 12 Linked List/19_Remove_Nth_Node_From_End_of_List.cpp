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
    int lenLL(ListNode* head){
        int length=0;
        while(head!=NULL){
            length++;
            head=head->next;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=lenLL(head);
        if(head==NULL)
            return NULL;

        if(n>length)
            return head;
        
        if(length==n)
            return head->next;
        
        int shift = length-n-1;
        ListNode* temp=head;
        while(shift--){
            if(temp!=NULL)
                temp=temp->next;
        }

        if(temp->next!=NULL)
            temp->next=temp->next->next;
            
        return head;
    }
};