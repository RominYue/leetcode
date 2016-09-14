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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL)return 0;
        vector<int> ans = getMax(root);
        return max(ans[0], ans[1]);
    }
    
    vector<int> getMax(TreeNode* root){
        vector<int> ret;
        if(root == NULL)
        {
            ret.push_back(0);
            ret.push_back(0);
            return ret;
        }
        
        vector<int> vleft = getMax(root->left);
        vector<int> vright = getMax(root->right);
        
        int tmp = 1, tmp2 = 0;
        if(root->left && root->val + 1 == root->left->val)tmp = max(tmp, vleft[0] + 1);
        if(root->right && root->val + 1 == root->right->val)tmp = max(tmp, vright[0] + 1);
        
        tmp2 = max(tmp, vleft[1]);
        tmp2 = max(tmp2, vright[1]);
        
        ret.push_back(tmp);
        ret.push_back(tmp2);
        
        //cout<<root->val<<" "<<ret[0]<<" "<<ret[1]<<endl;
        return ret;
        
    }
};