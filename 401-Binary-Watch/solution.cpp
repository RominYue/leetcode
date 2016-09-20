class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        if(num >= 9)return ans;

        for(int i = 0; i <= num; i++)
        {
            if(i > 3)continue;
            if(num - i > 5)continue;
            vector<string> v1, v2;
            dfs(i, 3, v1, 0, 0);
            dfs(num - i, 5, v2, 0, 0);

            for(int j = 0; j < v1.size(); j++)
            {
                for(int k = 0; k < v2.size(); k++)
                {
                    ans.push_back(v1[j] + ':' + v2[k]);
                }
            }
        }
        return ans;
    }

    void dfs(int k, int num, vector<string>& v, int pos, int val)
    {
        if(pos == num+1)
        {
            if(num == 5 && val < 60 && k == 0)
            {
                string t = to_string(val);
                if(t.size() == 1)t = '0' + t;
                v.push_back(t);
            }else if(num == 3 && val < 12 && k == 0){
                string t = to_string(val);
                v.push_back(t);
            }
            return;
        }
        dfs(k, num, v, pos+1, val);
        if(k > 0)dfs(k-1, num, v, pos+1, val + (1 << pos));
    }
};
