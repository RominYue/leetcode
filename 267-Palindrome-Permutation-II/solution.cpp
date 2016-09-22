class Solution {
public:
    map<char, int> cnt;
    vector<string> generatePalindromes(string s) {
        vector<string> ans;

        int len = s.size();
        if(len == 0)return ans;

        for(int i = 0; i < len; i++)cnt[s[i]]++;

        int count = 0;
        for(auto iter = cnt.begin(); iter != cnt.end(); iter++)
        {
            if(cnt[iter->first]&1)count++;
        }

        if(count > 1)return ans;
        if(count == 1 && len % 2 == 0)return ans;


        char ch='#';
        for(auto iter = cnt.begin(); iter != cnt.end(); iter++)
        {
            if(cnt[iter->first]&1)ch = iter->first;
            cnt[iter->first] /= 2;
        }

        vector<string> ret;
        dfs(0, len/2, ret, "");

        for(int i = 0; i < ret.size(); i++)
        {
            string tt;
            string rev = ret[i];
            reverse(ret[i].begin(), ret[i].end());
            if(ch != '#')tt = ret[i] + ch + rev;
            else tt = ret[i] + rev;
            ans.push_back(tt);
        }
        return ans;
    }

    void dfs(int k, int len, vector<string>& tmp, string ans)
    {
        if(k == len)
        {
            tmp.push_back(ans);
            return;
        }

        for(auto iter = cnt.begin(); iter != cnt.end(); iter++)
        {
            if(cnt[iter->first] <= 0)continue;
            char t = iter->first;
            cnt[iter->first]--;
            dfs(k+1, len, tmp, ans + t);
            cnt[iter->first]++;
        }
    }
};