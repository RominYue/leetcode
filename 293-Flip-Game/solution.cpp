class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ret;
        int len = s.size();
        if(len == 0 || len == 1)return ret;
        
        int cur = 0;
        while(cur < len - 1)
        {
            if(s[cur] == s[cur+1] && s[cur] == '+')
            {
                string t = s;
                t.replace(cur, 2, "--");
                ret.push_back(t);
            }
            cur++;
        }
        return ret;
    }
};