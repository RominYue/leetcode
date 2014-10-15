class Solution {
public:
    int atoi(const char *str) {
        //remove beginning space
        while(*str == ' ')str++;
        
        //deal with first non-space character
        if(!isdigit(*str) && *str != '-' && *str != '+')return 0;
        
        //judge positive or negetive
        int flag = 0;
        if(*str == '-' || *str == '+')
        {
            if(*str == '-') flag = 1;
            str ++;
        }

        //match as much digits as possible
        long long ans = 0;
        while(*str != '\0' && isdigit(*str))
        {
            ans = ans * 10 + *str - '0';
            str ++;
        }
        
        //check overflow
        if(flag) ans = -1 * ans;
        if(ans > INT_MAX ) ans = INT_MAX;
        if(ans < INT_MIN ) ans = INT_MIN;

        return ans;
    }
};
