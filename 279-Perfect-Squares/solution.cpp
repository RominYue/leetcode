class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = (int)1e9 + 7;
            for(int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};