/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
 * 高度为h的完全二叉树，其节点个数等于高度为h-1的满二叉树的节点个数 + 最后一层的节点个数。

因此，只需要二分枚举第h层的节点个数即可。

将第h层的节点从0至2^h - 1依次编号（根节点的层数记为0）

若用0表示左孩子，1表示右孩子，则这些编号的二进制形式是从根节点出发到叶子节点的“路径”。
 */
class Solution {
public:
    int getHeight(TreeNode *root)
    {
        int depth = 0;
        while(root)
        {
            depth++;
            root=root->left;
        }
        return depth;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;
        int h = getHeight(root);
        if(h == 1)return 1;
        int ans = (1 << (h-1)) - 1;
        
        int l = 0, r = (1 << (h-1)) - 1;
        while(l <= r)
        {
            int mid = (l+r) >> 1;
            if(getNode(root, mid, h-1))l = mid + 1;
            else r = mid - 1;
        }
        return ans + r + 1;
    }
    
    TreeNode* getNode(TreeNode* root, int path, int depth)
    {
        while(depth && root)
        {
            depth--;
            if(path & (1 << depth))
            {
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return root;
    }
};