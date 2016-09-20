class Solution {
public:
    int findNthDigit(int n) {
        if(n == 0)return 0;
        
        int len = 1;
        long long start = 1;
        long long cnt = 9;
        
        //确定是几位数
        while(n > len * cnt)
        {
            n -= len*cnt;
            len++;
            cnt *= 10;
            start *= 10;
        }
        
        //第几个数
        start += (long long)ceil(n*1.0/len) - 1;
        cout<<start<<endl;
        
        string t = to_string(start);

        return t[(n-1) % len] - '0';
    }
};