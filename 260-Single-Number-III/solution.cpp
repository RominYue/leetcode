class Solution {
/*
1. xor异或之后是两个数的异或, 记录为ret
2. 找到ret的低位第一个1，这个1标示了两个数的差异(该位上只有0 ^ 1 才会出现1，即表明一个数该位是1，一个数该位是0)
3. 将原数组依据该位分成两组，依次做异或即可
*/
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int ret = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        
        ret = ret & (-ret);
        
        int ret1 = 0, ret2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(ret & nums[i])
            {
                ret1 ^= nums[i];
            }
            else
            {
                ret2 ^= nums[i];
            }
        }
        
        ans.push_back(ret1);
        ans.push_back(ret2);
        return ans;
    }
};