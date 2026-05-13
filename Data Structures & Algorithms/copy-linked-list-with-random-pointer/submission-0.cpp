/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        //copying the original elements
        Node* curr=head;
        while(curr){
            Node* copy=new Node(curr->val);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }

        //copying the random pointer
        curr=head;
        while(curr){
            if(curr->random){
            curr->next->random=curr->random->next;}
            curr=curr->next->next;

        }

        //separating the two
        Node* original=head;
        Node* newHead=head->next;
        Node* copy=newHead;

        while(original){
            // Save next nodes first
        Node* originalNext = original->next->next;
        Node* copyNext = copy->next ? copy->next->next : nullptr;
    
        // Update pointers
        original->next = originalNext;
        if(copy->next) copy->next = copyNext;
    
        // Move to next nodes
        original = originalNext;
        copy = copyNext;
        }
        return newHead;
        
    }
};
