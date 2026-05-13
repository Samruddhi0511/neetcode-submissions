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
#include <queue>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //custom comparator for the heap since the heap is max by default
        auto cmp=[](ListNode* a, ListNode* b){
            return a->val> b->val;
        };
        //priority queue< what type of elements itll contain, from where theyre taken, constructor
        priority_queue<ListNode* , vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        //push all the first elements into the priority queue
        for(ListNode* list:lists){
            if (list){
                minHeap.push(list);
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* curr = dummy;
        //processing the nodes until the heap is empty
        while(!minHeap.empty()){
            ListNode* smallest=minHeap.top();
            minHeap.pop();

            curr->next=smallest;
            curr=curr->next;

            //move the next one into the heap
            if(smallest->next){
                minHeap.push(smallest->next);
            }
        }
        return dummy->next;

    }
};
