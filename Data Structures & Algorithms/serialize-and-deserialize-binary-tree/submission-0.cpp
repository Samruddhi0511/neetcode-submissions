/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        return to_string(root->val)+","+ serialize(root->left)+","+serialize(root->right);
        
    }

    vector<string> split(const string &data){
        vector<string> result;
        stringstream ss(data);
        string token;

        while(getline(ss, token, ',')){
            result.push_back(token);
        }

        
    return result;
    }
    TreeNode* buildTree(queue<string> &q){
        string val=q.front();
        q.pop();
        if (val=="null") return nullptr;
        TreeNode* root=new TreeNode(stoi(val));
        root->left=buildTree(q);
        root->right=buildTree(q);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> splits=split(data);
        queue<string> q;
        for(const string &s : splits){
            q.push(s);
        }

        return buildTree(q);
    }
};
