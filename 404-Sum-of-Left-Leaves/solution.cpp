/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)return 0;
        if(!root->left && !root->right)return 0;
        return process(root, 0);
    }
    
    int process(TreeNode* root, int flag){
        if(!root->left && !root->right)
        {
            if(flag == 0)return root->val;
            return 0;
        }
        
        int sumLeft = 0, sumRight = 0;
        if(root->left) sumLeft = process(root->left,0);
        if(root->right) sumRight = process(root->right, 1);
        return sumLeft + sumRight;
    }
};