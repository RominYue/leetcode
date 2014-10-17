class Solution {
public:
    int maxArea(vector<int> &height) {
        
        int start = 0, end = height.size() - 1;
        int ans = 0;
        
        while(start < end)
        {
            ans = max(ans,(end - start)*min(height[start],height[end]));
            if(height[start] < height[end]) start ++;
            else end --;
        }
        
        return ans;
    }
};
