class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        if(len == 0)return 0;
        
        if(m > len)m = len;
        long long dp[len][m+1];
        long long sum[len];
        memset(dp, 0, sizeof(dp));
        memset(sum,0,sizeof(sum));
        
        long long total = 0;
        for(int i = 0; i < len; i++){
            total += nums[i];
            sum[i] = total;
        }
        
        for(int i = 0; i < len; i++){
            for(int j = 1; j <= m; j++)
            {
                if(i+1 < j)continue;
                if(j == 1)dp[i][1] = sum[i]; //bound condition
                else{
                    long long ret = 1e16;
                    for(int k = 0; k < i; k++)
                    {
                        if(k+1 < j-1)continue;
                        //cout<<k<<" "<<m-1<<" "<<dp[k][m-1]<<endl;
                        long long tmp = max(dp[k][j-1], sum[i] - sum[k]);
                        ret = min(tmp, ret);
                    }
                    dp[i][j] = ret;
                }
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        
        return dp[len-1][m];
    }
};