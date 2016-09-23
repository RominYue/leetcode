//只需保存上一轮第一小和第二小的数及其位置
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0)return 0;
        int k = costs[0].size();
        if(k == 0)return 0;
        
        int dp[n][k];
        memset(dp,0,sizeof(dp));
        
        int val_1 = INT_MAX, val_2 = INT_MAX;
        int pos_1 = 0;
        
        for(int i = 0; i < k; i++)
        {
            dp[0][i] = costs[0][i];
            if(dp[0][i] < val_1)
            {
                val_2 = val_1;
                val_1 = dp[0][i];
                pos_1 = i;
            }else if(dp[0][i] < val_2){
                val_2 = dp[0][i];
            }
        }

        for(int i = 1; i < n; i++)
        {
            int tmp_min = INT_MAX, tmp_secMin = INT_MAX;
            int tmp_pos = 0;
            for(int j = 0; j < k; j++)
            {
                if(j == pos_1)dp[i][j] = val_2 + costs[i][j];
                else dp[i][j] = val_1 + costs[i][j];
                if(dp[i][j] < tmp_min)
                {
                    tmp_secMin = tmp_min;
                    tmp_min = dp[i][j];
                    tmp_pos = j;
                }else if(dp[i][j] < tmp_secMin){
                    tmp_secMin = dp[i][j];
                }
            }
            
            val_1 = tmp_min;
            val_2 = tmp_secMin;
            pos_1 = tmp_pos;
        }
        
        return val_1;
    }
};