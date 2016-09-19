class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)return 0;
        if(k == 1)
        {
            if(n <= 2)return 1;
            return 0;
        }
        if(n == 1)return k;
        
        int adj_true = k;
        int adj_false = k*(k-1);
        
        int ans = max(adj_true, adj_false);
        
        for(int i = 3; i <= n; i++)
        {
            int now_adj_true = adj_false;
            int now_adj_false = (adj_false + adj_true)*(k-1);
            ans = max(now_adj_true, now_adj_false);
            adj_false = now_adj_false;
            adj_true = now_adj_true;
        }
        
        return adj_true + adj_false;
    }
};