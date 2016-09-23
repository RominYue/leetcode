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
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL)return 0;
        
        vector<int> ans = process(root);
        return ans[0];
    }
    
    vector<int> process(TreeNode* root)
    {
        vector<int> ret;
        if(!root->left && !root->right)
        {
            ret.push_back(1);
            ret.push_back(1);
            return ret;
        }
        vector<int> left_num, right_num;
        if(root->left) left_num = process(root->left);
        if(root->right) right_num = process(root->right);
        
        if(root->left && root->right)
        {
            if(left_num[1] == 1 && right_num[1] == 1 && root->left->val == root->val && root->right->val == root->val){
                ret.push_back(left_num[0] + right_num[0] + 1);
                ret.push_back(1);
                return ret;
            }
            ret.push_back(left_num[0] + right_num[0]);
            ret.push_back(0);
            return ret;
        }else if(root->left){
            if(left_num[1] == 1 && root->left->val == root->val){
                ret.push_back(left_num[0] + 1);
                ret.push_back(1);
                return ret;
            }
            ret.push_back(left_num[0]);
            ret.push_back(0);
            return ret;
        }else{
            if(right_num[1] == 1 && root->right->val == root->val){
                ret.push_back(right_num[0] + 1);
                ret.push_back(1);
                return ret;                
            }
            ret.push_back(right_num[0]);
            ret.push_back(0);
            return ret;
        }
    }
    
};