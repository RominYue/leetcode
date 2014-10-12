class Solution {
public:
    string longestPalindrome(string s) {
        bool ok[1100][1100];
        int start_index = 0, maxlen = 1,slen = s.size();
        memset(ok,false,sizeof(ok));
        //process with only one character
        for(int i = 0; i < slen; i++) ok[i][i] = true;
        //process with two characters
        for(int i = 0; i < slen - 1; i++)
        {
            if(s[i] == s[i+1])
            {
                ok[i][i+1] = true;
                start_index = i;
                maxlen = 2;
            }
        }
        //brute force from len 3 ~ s.size()
        for(int len = 3; len <= slen; len++)
        {
            for(int i = 0; i <= slen - len; i++)
            {
                int j = i + len - 1;
                if(s[i] == s[j] && ok[i+1][j-1])
                {
                    ok[i][j] = true;
                    start_index = i;
                    maxlen = max(maxlen, len);
                }
            }
        }
        return s.substr(start_index,maxlen);
    }
};
