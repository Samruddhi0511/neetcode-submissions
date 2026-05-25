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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return ;
        int n=0;
        ListNode* curr=head;
        while(curr){
            n++;
            curr=curr->next;
        }

        //n is the len of the linked list
        ListNode* end_of_first=head;
        int steps=(n-1)/2;
        while(steps--){
            end_of_first=end_of_first->next;
        }
        //now we have the head of the second half pf the ll we reverse it
        ListNode* head2=end_of_first->next;
        end_of_first->next=nullptr;
        ListNode* prev=nullptr;
        curr=head2;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head2=prev;

        ListNode* head1=head;
        
        while(head2){
           ListNode* next1=head1->next;
           ListNode* next2=head2->next;
           head1->next=head2;
           head2->next=next1;
           head1=next1;
           head2=next2;
        }
        

    }
};
