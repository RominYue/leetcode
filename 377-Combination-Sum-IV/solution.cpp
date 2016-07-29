/*
dp[i] = sigma(dp[i - nums[j]])
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i <= target; i++)
        {
            int tmp = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                if(i >= nums[j])
                    tmp += dp[i - nums[j]];
            }
            dp[i] = tmp;
        }
        return dp[target];
    }
};