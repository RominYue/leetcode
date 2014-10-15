class Solution {
public:
    string convert(string s, int nRows) {
        
        //speical case with row = 1
        if(nRows == 1)return s;
        
        string ans = "";
        vector<char> v[1000];
        int flag = 1, num = 0;
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(flag)
            {
                v[++num].push_back(s[i]);
                if(num == nRows)flag = 0;
            }
            else
            {
                v[--num].push_back(s[i]);
                if(num == 1)flag = 1;
            }
        }
        for(int i = 1; i <= nRows; i++)
        {
            len = v[i].size();
            for(int j = 0; j < len; j++)
            ans += v[i][j];
        }
        return ans;
    }
};
