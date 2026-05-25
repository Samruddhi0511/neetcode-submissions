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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode* curr=head;
        while(curr){
            l++;
            curr=curr->next;
        }
        l=l-n+1;
        curr=head;
        if(l==1){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        while(l>2){
            curr=curr->next;
            l--;
        }
        //it has reached before the node to be deleted
        ListNode* next=curr->next->next;
        curr->next->next=nullptr;
        delete curr->next;
        curr->next=next;
        

        return head;
    }
};
