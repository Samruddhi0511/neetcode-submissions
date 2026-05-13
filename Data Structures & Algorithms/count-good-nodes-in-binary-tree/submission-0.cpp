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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* root , int maxSoFar){
        //base case
        if(!root){
            return 0;
        }

        int good=0;
        if(root->val >= maxSoFar){
            good=1;
        }
        maxSoFar=max(root->val, maxSoFar);
        good+=dfs(root->left,maxSoFar);
        good+=dfs(root->right, maxSoFar);

        return good;
    }
};
