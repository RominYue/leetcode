class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans;
        int len = nums.size();
        if(len == 0)return ans;
        
        if(a == 0)
        {
            if(b == 0)return vector<int>(len, c);
            else if(b > 0)
            {
                for(int i = 0; i < len; i++)ans.push_back(b*nums[i] + c);
                return ans;
            }else{
                for(int i = len-1; i >= 0; i--)ans.push_back(b*nums[i] + c);
                return ans;
            }
        }else if(a > 0)
        {
            int optimize = (-b)/(2*a);
            int pos = binary_search(nums, optimize);
            ans = merge(nums, pos, len-1, pos-1, 0, a, b, c);
        }else{
            int optimize = (-b)/(2*a);
            int pos = binary_search(nums, optimize);
            ans = merge(nums, 0, pos-1, len-1, pos, a, b, c);
        }
        return ans;
    }
    
    int binary_search(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] < target)l=mid + 1;
            else r = mid-1;
        }
        return l;
    }
    
    vector<int> merge(vector<int> nums, int l1, int r1, int l2, int r2, int a, int b, int c)
    {
        vector<int> ret;
        int i = l1, j = l2;
        while(i <= r1 || j >= r2)
        {
            if(i <= r1 && j >= r2)
            {
                if(cal(nums[i],a,b,c) < cal(nums[j],a,b,c))
                {
                    ret.push_back(cal(nums[i],a,b,c));
                    i++;
                }else{
                    ret.push_back(cal(nums[j],a,b,c));
                    j--;
                }
            }
            else if(i <= r1)
            {
                ret.push_back(cal(nums[i++],a,b,c));
            }else{
                ret.push_back(cal(nums[j--],a,b,c));
            }
        }
        return ret;
    }
    
    int cal(int x, int a, int b, int c)
    {
        return a*x*x + b*x + c;
    }
};