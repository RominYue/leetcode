class Solution {
public:
    struct Node
    {
        int val;
        int row;
        int col;
        bool operator < (Node a)const{
            return val < a.val;
        }
        bool operator > (Node a)const{
            return val > a.val;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n == 0)return 0;

        priority_queue<Node, vector<Node>, greater<Node> > q;
        Node tmp;
        for(int i = 0; i < n; i++)
        {
            tmp.val = matrix[0][i];
            tmp.row = 0;
            tmp.col = i;
            q.push(tmp);
        }
        int cnt = 0;
        while(!q.empty())
        {
            Node x = q.top();
            q.pop();
            cnt ++;
            if(cnt == k)
            {
                return x.val;
            }
            if(x.row + 1 < n)
            {
                tmp.row = x.row + 1;
                tmp.col = x.col;
                tmp.val = matrix[tmp.row][tmp.col];
                q.push(tmp);
            }
        }
        return 0;
    }
};