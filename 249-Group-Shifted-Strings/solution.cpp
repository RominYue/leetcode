class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, int> m;
        for(int i = 0; i < strings.size(); i++)m[strings[i]]++;
        
        vector<vector<string> > ans;
        while(m.size() != 0)
        {
            auto iter = m.begin();
            vector<string> tmp;
            for(int i = 0; i < iter->second; i++)tmp.push_back(iter->first);
            
            string cur = iter->first;
            for(int i = 1; i < 26; i++)
            {
                string t = "";
                for(int j = 0; j < cur.size(); j++)
                    t += (cur[j] - 'a' + i) % 26 + 'a';
                
                auto it = m.find(t);
                if(it != m.end())
                {
                    for(int i = 0; i < it->second; i++)tmp.push_back(it->first);
                    m.erase(it);
                }
            }
            m.erase(iter);
            ans.push_back(tmp);
        }
        return ans;
    }
};