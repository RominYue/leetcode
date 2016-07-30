class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        if(len == 0)return ans;
        int dp[len], path[len];
        
        dp[0] = 1;
        memset(path,-1,sizeof(path));
        sort(nums.begin(),nums.end());
        
        //dp
        for(int i = 1; i < len; i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if((nums[i] % nums[j]) == 0)
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        path[i] = j;
                    }
                }
            }
        }
        
        int pos = 0, maxval = 0;
        for(int i = 0; i < len; i++)
        {
            if(dp[i] > maxval)
            {
                maxval = dp[i];
                pos = i;
            }
        }
        //print path
        stack<int> s;
        while(pos != -1)
        {
            s.push(pos);
            pos = path[pos];
        }
        
        while(!s.empty())
        {
            int x = s.top();
            s.pop();
            ans.push_back(nums[x]);
        }
        return ans;
    }
};