class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), cmp);
        int ret = 0;
        for(int i = 0; i < citations.size(); i++)
        {
            ret = max(ret, min(citations[i], i+1));
        }
        return ret;
    }
    static bool cmp(int a, int b)
    {
        return a > b;
    }
};