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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for(int i=0;i<inorder.size();i++){
            inorder_map[inorder[i]]=i;
        }

        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inorder_map);
    }

    TreeNode* buildTree(vector<int> preorder, int prestart, int preend, vector<int> inorder, int instart, int inend, unordered_map<int, int> & inorder_map){
        //base case
        if(prestart>preend || instart> inend){
            return nullptr;
        }

        //root is the first value of preorder
        int root_value=preorder[prestart];
        TreeNode* root=new TreeNode(root_value);
        //position 
        int root_pos=inorder_map[root->val];


        //calculate from inorder
        int left_size=root_pos-instart;

        root->left=buildTree(preorder,prestart+1, prestart+left_size,inorder, instart, root_pos-1, inorder_map);
        root->right=buildTree(preorder, prestart+left_size+1, preend, inorder, root_pos+1, inend, inorder_map);

        return root;
    }
};

