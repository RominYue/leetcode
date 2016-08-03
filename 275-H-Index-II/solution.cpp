class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size() - 1;
        int ret = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            int diff = citations.size() - mid;
            if(citations[mid] < diff) l = mid + 1;
            else
            {
                ret = max(ret, diff);
                r = mid - 1;
            }
        }
        return ret;
    }
};