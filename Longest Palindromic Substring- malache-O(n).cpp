class Solution {
public:
    string longestPalindrome(string s) {
        char str[2200];
        //process with string s
        int n = s.size();
        str[0] = '@';
        str[1] = '#';
        for(int i = 0; i < n; i++)
        {
            str[2*i + 2] = s[i];
            str[2*i + 3] = '#';
        }
        n = n*2 + 2;
        str[n] = '\0';

        //malache algorithm
        int p[2200], maxrange = 0, id = 0;
        memset(p,0,sizeof(p));
        for(int i = 1; i < n ; i++)
        {
            if(i < maxrange) p[i] = min(p[2*id - i],maxrange- i);
            else p[i] = 1;

            while(str[i + p[i]] == str[i - p[i]]) p[i] ++;

            if(p[i] + i > maxrange)
            {
                maxrange = p[i] + i;
                id = i;
            }
        }

        //find the maximum p[i] - 1
        int maxlen = 1,minid = 1;
        for(int i = 0; i < n; i++)
        {
            if(p[i] - 1 > maxlen)
            {
                maxlen = p[i] - 1;
                minid = i;
            }
        }
        return s.substr((minid - p[minid])/2,maxlen);
    }
};
