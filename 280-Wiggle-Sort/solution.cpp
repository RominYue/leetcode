class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)return;
        
        sort(nums.begin(), nums.end());
        
        int cur = 1;
        while(cur < len-1)
        {
            swap(nums[cur], nums[cur+1]);
            cur += 2;
        }
    }
};