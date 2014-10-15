class Solution {
public:
    int reverse_positive(int x)
    {
        int ans = 0;
        while(x != 0)
        {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
    int reverse(int x) {
        if(x > 0)return reverse_positive(x);
        return -1*reverse_positive(-1 *x);
    }
};
