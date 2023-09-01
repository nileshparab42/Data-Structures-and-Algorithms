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
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0){
            return head;
        }
        if(head==NULL){
            return NULL;
        }
        int length = lenLL(head);
        int r = k%length;
        if(r == 0){
            return head;
        }
        int shifts = length - r - 1;
        ListNode* temp = head;
        while(shifts--){
            temp=temp->next;
        }

        ListNode* prevHead = head;
        head = temp->next;
        temp->next = NULL;

        ListNode* end = head;
        while(end->next!=NULL){
            end=end->next;
        }
        end->next = prevHead;

        return head; 
    }
};