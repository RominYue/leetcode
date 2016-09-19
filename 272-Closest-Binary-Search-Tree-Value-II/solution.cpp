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
    struct Node
    {
        int val;
        double diff;
        Node(int a, double b): val(a), diff(b){}
        bool operator < (Node a) const
        {
            return diff <= a.diff;
        }
        bool operator > (Node a) const
        {
            return diff > a.diff;
        }
    };
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<Node, vector<Node>, greater<Node> > pq;
        process(root, target, pq);
        
        vector<int> ans;
        int cnt = 0;
        while(!pq.empty())
        {
            if(cnt == k)break;
            Node x = pq.top();
            ans.push_back(x.val);
            pq.pop();
            cnt++;
        }
        return ans;
    }
    
    void process(TreeNode* root, double target, priority_queue<Node, vector<Node>, greater<Node> >& pq)
    {
        if(root == NULL)return;
        double tmp = fabs(target - root->val);
        pq.push(Node(root->val,tmp));
        process(root->left, target, pq);
        process(root->right, target, pq);
    }
};