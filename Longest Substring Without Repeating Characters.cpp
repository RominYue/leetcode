class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idx[256], maxlength = 0,lastindex = -1;
        memset(idx, -1 ,sizeof(idx));
        // idx数组存的是字符对应的是上一个重复字符对应的下标
        for(int i = 0; i < s.size(); i++)
        {
            if(lastindex < idx[s[i]])lastindex = idx[s[i]];
            maxlength = max(maxlength, i - lastindex);
            idx[s[i]] = i;
        }
        return maxlength;
    }
};
