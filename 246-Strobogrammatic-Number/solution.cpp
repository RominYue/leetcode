class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char, char> m;
        m['0'] = '0';
        m['1'] = '1';
        m['8'] = '8';
        m['6'] = '9';
        m['9'] = '6';
        
        int l = 0, r = num.size()-1;
        while(l <= r)
        {
            if(m.find(num[l]) == m.end())return false;
            if(m[num[l]] != num[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};