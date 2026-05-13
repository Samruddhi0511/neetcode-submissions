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
        //finding the length of linked list
        ListNode* temp=head;
        int length=0;
        while(temp!=nullptr){
            length++;
            temp=temp->next;
        }
        //edge case
        if(n==length){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }

        //now length of the linked list is known
        int count=0;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(count!=(length-n)){
            count++;
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete curr;

        return head;
    }
};
