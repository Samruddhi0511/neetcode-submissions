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
    int i=0;
    void serializeHelper(TreeNode* root, string &result){
        if(root==nullptr) {result = result + "#" + ','; return; }
        
            result = result + to_string(root->val) + ',';
            serializeHelper(root->left, result);
            serializeHelper(root->right, result);
        
    }

    TreeNode* deserializeHelper(string data){
        if(data.size()<=i) return nullptr;
        
            
            string token="";
            while(i<data.size() && data[i]!=','){
                token = token + data[i++];
            }
            i++;
            if(token == "#") return nullptr;

            TreeNode* temp= new TreeNode(stoi(token));
            temp->left=deserializeHelper(data);
            temp->right=deserializeHelper(data);
            return temp;
           
        
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result="";
        serializeHelper(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        i=0;
       return deserializeHelper(data);
    }
};
