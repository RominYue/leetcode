class Solution {
public:
    bool canPermutePalindrome(string s) {
        int len = s.size();
        if(len == 0)return true;
        
        map<char, int> m;
        for(int i = 0; i < len; i++)m[s[i]]++;
        
        int odd_num = 0;
        for(auto iter = m.begin(); iter != m.end(); iter++)
        {
            if(m[iter->first]&1)odd_num++;
        }
        
        if(odd_num > 1)return false;
        if(odd_num == 1)
        {
            if(len&1)return true;
            return false;
        }
        if(len&1)return false;
        return true;
    }
};