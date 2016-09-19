class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        return process(s, 2);
    }
    
    int process(string s, int k)
    {
        int len = s.size();
        if(len <= 1)return len;
        
        map<char, int> m;
        int ret = 0;
        
        int start = 0, cur = 0;
        while(cur < len)
        {
            m[s[cur]]++;
            cout<<start<<" "<<cur<<endl;
            if(m.size() > k)
            {
                while(m.size() > k)
                {
                    m[s[start]] --;
                    if(m[s[start]] == 0)m.erase(s[start]);
                    start++;
                }
                ret = max(ret, cur - start + 1);
                cur++;
            }else{
                ret = max(ret, cur - start + 1);
                cur++;
            }
        }
        return ret;
    }
};