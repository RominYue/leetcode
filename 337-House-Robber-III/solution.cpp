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
    int rob(TreeNode* root) {
        vector<int> ret = tree_dp(root);
        return max(ret[0],ret[1]);
    }

    vector<int> tree_dp(TreeNode* root)
    {
        vector<int> ret(2,0);
        if(root == NULL)
        {
            return ret;
        }
        vector<int> left = tree_dp(root->left);
        vector<int> right = tree_dp(root->right);
        
        ret[0] = max(left[0],left[1]) + max(right[0],right[1]);
        ret[1] = left[0] + right[0] + root->val;
        return ret;
    }

};