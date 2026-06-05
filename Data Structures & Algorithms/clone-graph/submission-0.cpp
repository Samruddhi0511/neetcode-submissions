/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> old2new;
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;

        if(old2new.find(node)!=old2new.end()){
            return old2new[node];
        }

        Node* clone=new Node(node->val);
        old2new[node]=clone;

        for(Node* neighbour : node->neighbors){
            clone->neighbors.push_back(cloneGraph(neighbour));
        }
        return clone;
    }
};
