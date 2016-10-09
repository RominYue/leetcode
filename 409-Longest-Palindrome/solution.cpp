class Solution {
public:
    int longestPalindrome(string s) {
        int lower_cnt[26];
        int upper_cnt[26];
        memset(lower_cnt, 0, sizeof(lower_cnt));
        memset(upper_cnt, 0, sizeof(upper_cnt));
        
        for(int i = 0; i < s.size(); i++)
        {
            if(isupper(s[i])) upper_cnt[s[i] - 'A']++;
            else lower_cnt[s[i] - 'a']++;
        }
        
        int ans = 0, odd = 0;
        for(int i = 0; i < 26; i++)
        {
            if((upper_cnt[i]&1) || (lower_cnt[i]&1))odd = 1;
            ans += upper_cnt[i]/2;
            ans += lower_cnt[i]/2;
        }
        return ans*2 + odd;
    }
};