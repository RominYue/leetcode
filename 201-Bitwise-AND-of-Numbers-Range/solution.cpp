class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n)return m;
        int cnt = 0;
        while(m != n)
        {
            m >>= 1;
            n >>= 1;
            cnt++;
        }
        return m * (1 << cnt);
    }
};