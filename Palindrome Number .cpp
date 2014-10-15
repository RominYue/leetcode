class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long reverseint = 0, tmpx = x;
        while(x != 0)
        {
            reverseint = reverseint * 10 + x % 10;
            x /= 10;
        }
        return reverseint == tmpx;
    }
};
