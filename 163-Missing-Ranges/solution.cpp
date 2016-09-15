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
        
        //push INT_MAX, consider nums[len-1] < upper
        //nums.insert(nums.begin(), INT_MIN);
        //nums.push_back(INT_MAX);
        
        //bool first = true;
        //bool modified_lower = false;
        int pre = lower;
        for(int i = 0; i < nums.size(); i++)
        {

            //check lower
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
            
            pre = lower;
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