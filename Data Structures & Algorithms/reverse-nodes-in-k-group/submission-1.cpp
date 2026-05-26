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

        // dummy -> [1,2,3] -> 4
        //dummy->[3,2,1] ->4
        //therefore v need last of prevgrp, first of curr grp, last of curr grp, first of next grp
        ListNode dummy(0);
        dummy.next=head;
        //rn dummy is prevgrp
        ListNode* prevgrp=&dummy;
        while(true){
            ListNode* start=prevgrp->next;
            ListNode* kth=prevgrp;
            for(int i=0; i<k; i++){
                kth=kth->next;
                if(!kth) return dummy.next;
            }
            //kth is last of curr grp
            ListNode* nextgrp=kth->next;
            ListNode* curr=start;
            ListNode* prev=nextgrp;

            while(curr!=nextgrp){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }

            prevgrp->next=kth;
            start->next=nextgrp;
            prevgrp=start;
        }
    }
};