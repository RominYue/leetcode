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
    int closestValue(TreeNode* root, double target) {
        int ans = 0;
        double diff = 1e15 + 10;
        process(root, target, ans, diff);
        return ans;
    }
    
    void process(TreeNode* root, double target, int& ans, double& diff)
    {
        if(root == NULL)return;
        double tmp = fabs(target - root->val);
        if(tmp < diff)
        {
            ans = root->val;
            diff = tmp;
        }
        process(root->left, target, ans, diff);
        process(root->right, target, ans, diff);
    }
};