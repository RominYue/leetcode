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
    
    void Inorder(TreeNode* root, vector<int>& nums)
    {
        if(root == NULL)return;
        Inorder(root->left, nums);
        nums.push_back(root->val);
        Inorder(root->right, nums);
    }
    
    int binarySearch(vector<int>&nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int mid;
        while(l <= r)
        {
            mid = l + (r-l)/2;
            if(mid == target)return nums[target];
            else if(mid > target)r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        Inorder(root, nums);
        int ans = binarySearch(nums,k-1);
        return ans;
    }
};