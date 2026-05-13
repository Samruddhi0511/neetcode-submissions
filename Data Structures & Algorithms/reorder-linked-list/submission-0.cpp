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
        if (!head || !head->next) return;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* h1=head;
        ListNode* h2=slow->next;
        slow->next=nullptr;

        //reverse the second list
        ListNode* prev=nullptr;
        ListNode* curr=h2;
        while(curr!=nullptr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        h2=prev;
        ListNode* curr1=h1;
        ListNode* curr2=h2;
        ListNode* new_head;
        new_head=curr1;
        //new reordered list
        while(curr1!=nullptr && curr2!=nullptr){
            ListNode* temp1=curr1->next;
            ListNode* temp2=curr2->next;

            curr1->next=curr2;
            curr2->next=temp1;

            curr1=temp1;
            curr2=temp2;
        }
        
    }
};
