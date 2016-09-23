class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        return dis(s,t) && dis(t,s);
    }
    
    bool dis(string s, string t)
    {
        int lens = s.size();
        int lent = t.size();
        
        if(lens == lent){
            int cnt = 0;
            for(int i = 0; i < lens; i++)
                if(s[i] != t[i])cnt++;
            return cnt == 1;
        }else if(lens - lent == 1){
            if(s.substr(1, lens-1) == t)return true;
            if(s.substr(0, lens-1) == t)return true;
            for(int i = 1; i < lens-1; i++)
            {
                if(s.substr(0, i) + s.substr(i+1, lens-i-1) == t)return true;
            }
            return false;
        }else if(lent - lens == 1){
            if(t.substr(1, lent-1) == s)return true;
            if(t.substr(0, lent-1) == s)return true;
            for(int i = 1; i < lent-1; i++)
            {
                if(t.substr(0, i) + t.substr(i+1, lent-i-1) == s)return true;
            }
            return false;
        }
        return false;
    }
};