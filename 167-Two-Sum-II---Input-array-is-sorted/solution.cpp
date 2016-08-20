class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        vector<int> ans;
        if(len == 0 || len == 1)return ans;
        
        for(int i = 0; i < numbers.size(); i++)
        {
            int diff = target - numbers[i];
            int index = binary_search(numbers, i+1, len-1, diff);
            if(index != -1)
            {
                ans.push_back(i+1);
                ans.push_back(index + 1);
                break;
            }
        }
        return ans;
    }
    
    int binary_search(vector<int>&nums, int l, int r, int target)
    {
        if(l > r)return -1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};