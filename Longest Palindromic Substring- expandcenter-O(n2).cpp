class Solution {
public:
    string expand_around_center(string s, int c1, int c2)
    {
        int l = c1, r = c2, n = s.size();
        while(l >= 0 && r <= n-1 && s[l] == s[r])
        {
            l --;
            r ++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        if(s.size() == 0)return "";
        string ans = s.substr(0,1);
        for(int i = 0; i < s.size() - 1; i ++)
        {
            string tmp = expand_around_center(s,i,i);
            if(tmp.size() > ans.size()) ans = tmp;

            tmp = expand_around_center(s,i,i+1);
            if(tmp.size() > ans.size()) ans = tmp;
        }
        return ans;
    }
};
