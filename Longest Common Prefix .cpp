class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        
        int minlen = 1e9 + 7, num = strs.size();
        if(num == 0)return "";
        
        //find the minimum length of string
        for(int i = 0; i < num; i++)
        minlen = min(minlen,(int)strs[i].size());

        //find longest prefix
        string ans = "";
        for(int i = 0; i < minlen; i++)
        {
            bool ok = true;
            for(int j = 0; j < num; j++)
            {
                if(strs[j][i] != strs[0][i])
                {
                    ok = false;
                    break;
                }
            }
            if(ok)ans += strs[0][i];
            else break;
        }
        return ans;
    }
};
