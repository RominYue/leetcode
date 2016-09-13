/*
利用kmp相同前缀后缀的思想

这道题求原串中以开头字符开始的最长的回文串，然后将剩下的字符补全在前面即可。如何求出最长的回文子串？
一个Palindrome，reverse之后和之前是一样的，利用这个性质，将原串+reverse（原串），最长的公共前缀后缀就是原串中最长的回文子串
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = '#' + s + '#' + r;

        int len = t.size();
        int next[len];

        int j = 0;
        next[1] = 0;
        for(int i = 2; i < len; i++){
            while(j > 0 && t[i] != t[j+1])j = next[j];
            if(t[i] == t[j+1])j++;
            next[i] = j;
        }

        int common = next[len-1];
        string tmp = s.substr(common, s.size()-common);
        reverse(tmp.begin(), tmp.end());

        return tmp + s;
    }
};