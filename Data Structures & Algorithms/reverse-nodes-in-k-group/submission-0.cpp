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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        int count=0;

        //count the number of the nodes
        while(curr){
            curr=curr->next;
            count++;
        }
        curr=head;
        int remainder=count%k;
        int groups=(count-remainder)/k;

        for(int i=0;i<groups;i++){
            ListNode* groupPrev=prev;
            ListNode* groupStart=curr;

            for(int j=0;j<k;j++){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            //connect the reversed grp;
            groupStart->next=curr;
            groupPrev->next=prev;

            prev=groupStart;
        }
        return dummy->next;

    }
};
