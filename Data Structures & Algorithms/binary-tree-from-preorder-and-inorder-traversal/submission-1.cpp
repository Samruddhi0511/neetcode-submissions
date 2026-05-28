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
    unordered_map<int, int> map;
    int idx=0;
    TreeNode* build(vector<int> pre, int start, int end){
        if(start>end) return nullptr;
        int root_val=pre[idx++];
        TreeNode* root=new TreeNode(root_val);
        int mid=map[root_val];
        root->left= build(pre, start, mid-1);
        root->right=build(pre, mid+1, end);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            map[inorder[i]]=i;
        }
        return build(preorder, 0, inorder.size()-1);
        
    }
};
