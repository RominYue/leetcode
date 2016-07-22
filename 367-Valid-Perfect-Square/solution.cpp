/*
任意一个完全平方数 = 1 + 3 + 5 + 7.....
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int ret = 1;
        while(num > 0)
        {
            num -= ret;
            ret += 2;
        }
        if(num == 0)return true;
        return false;
    }
};