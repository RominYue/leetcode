/*
遍历数组，有以下几种情况

//[lower, upper] 在 nums 的左边

//[lower, uppper] 在 nums的右边

//[lower, uppper] 与nums交叉

if num[i] < lower; continue
else if num[i] == lower; lower++;
else if num[i] > lower
    if(num[i] <= uppper) add range;
    else num[i] > uppper break;
*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        
        //corner case
        if(lower > upper)return ans;
        
        if(nums.size() == 0)
        {
            string tmp = "";
            if(upper == lower)tmp = to_string(lower);
            else tmp = to_string(lower) + "->" + to_string(upper);
            ans.push_back(tmp);
            return ans;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {

            if(nums[i] < lower)continue;
            
            if(nums[i] == lower)
            {
                lower++;
                continue;
            }
            
            if(nums[i] > upper)
            {
                break;
            }
            
            string tmp = "";
            if(lower + 1 == nums[i]) tmp = to_string(lower);
            else tmp = to_string(lower) + "->" + to_string(nums[i]-1);
            ans.push_back(tmp);
            
            lower = nums[i] + 1;
        }
        
        if(lower <= upper)
        {
            string tmp = "";
            if(lower == upper) tmp = to_string(lower);
            else tmp = to_string(lower) + "->" + to_string(upper);
            ans.push_back(tmp);
        }

        return ans;
    }
};