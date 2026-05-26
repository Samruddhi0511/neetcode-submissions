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
ListNode* merge2ll(ListNode* head1, ListNode* head2){
    ListNode* curr1=head1;
    ListNode* curr2=head2;
    ListNode dummy(0);
    ListNode* tail=&dummy;
    while(curr1 && curr2){
        if(curr1->val < curr2->val){
            tail->next=curr1;
            curr1=curr1->next;
            tail=tail->next;
        }
        else{
            tail->next=curr2;
            curr2=curr2->next;
            tail=tail->next;
        }
    }
    if(curr1) tail->next=curr1;
    if(curr2) tail->next=curr2;
    return dummy.next;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) return nullptr;
        for(int i=1; i<lists.size(); i++){
            ListNode* head1=lists[i-1];
            ListNode* head2=lists[i];
            ListNode* newHead=merge2ll(head1, head2);
            lists[i]=newHead;

        }

        return lists[lists.size()-1];
    }
};
