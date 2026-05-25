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
        if(!head) return nullptr;
        unordered_map<Node*, Node*> old_2_new;

        //pass1:create all new nodes with values and map them to old node
        Node* curr=head;
        while(curr){
            old_2_new[curr]=new Node(curr->val);
            curr=curr->next;
        }

        //pass2 connect the next and random

        curr=head;
        while(curr){
            //address
            Node* cloneNode=old_2_new[curr];
            cloneNode->next=old_2_new[curr->next];
            cloneNode->random=old_2_new[curr->random];
            curr=curr->next;
        }

        return old_2_new[head];
        
    }
};
