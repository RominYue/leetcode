class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)return 0;
        sort(nums.begin(),nums.end());
        
        int cnt = 0;
        for(int k = 0; k < len - 2; k++)
        {
            for(int i = k+1, j = len-1; i < j;)
            {
                //if(nums[i] == nums[k])continue;
                if(nums[k] + nums[i] + nums[j] < target)
                {
                    cnt += j-i;
                    i++;
                }else{
                    j--;
                }
            }
        }
        
        return cnt;
    }
};