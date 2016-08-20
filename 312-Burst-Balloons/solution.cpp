class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)return 0;
        int vec[len + 2];
        //remove 0 and add first and last virtual element
        int tmp = 1;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] > 0) vec[tmp++] = nums[i];
        }
        vec[0] = vec[tmp] = 1;

        //dp process dp[l][r] = max(dp[l][k] + dp[k][r]) for k in (l,r), k is the last element to burst
        int dp[1005][1005];
        memset(dp, -1, sizeof(dp));
        divide_and_counter(vec, dp, 0, tmp);
        return dp[0][tmp];

    }

    int divide_and_counter(int vec[], int dp[][1005], int l, int r)
    {
        if(dp[l][r] != -1)return dp[l][r];
        if(l + 1 == r) return 0;
        int tmp = 0;
        for (int k = l + 1; k < r; k++)
        {
            dp[l][k] = divide_and_counter(vec, dp, l, k);
            dp[k][r] = divide_and_counter(vec, dp, k, r);
            tmp = max(tmp, dp[l][k] + dp[k][r] + vec[k]*vec[l]*vec[r]);
        }
        dp[l][r] = tmp;
        return dp[l][r];
    }
};