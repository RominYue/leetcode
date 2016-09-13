class Solution {
public:
    vector<int> v;
    Solution(vector<int> nums) {
        v = nums;
    }
    
    int pick(int target) {
        int count = 0;
        int ret = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] != target)continue;
            if(rand()%(++count) == 0)ret = i;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */