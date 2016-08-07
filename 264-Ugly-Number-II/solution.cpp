class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        int cnt = 1;
        int ans = 0;
        set<long long> s;
        s.insert(2);
        s.insert(3);
        s.insert(5);
        while(cnt != n)
        {
            set<long long>::iterator iter = s.begin();
            long long val = *iter;
            ans = val;
            s.erase(iter);
            cnt++;
            s.insert(val*2);
            s.insert(val*3);
            s.insert(val*5);
        }
        return ans;
    }
};