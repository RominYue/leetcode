class Solution {
public:
    map<char, char> m;
    
    Solution(){
        m['1'] = '1';
        m['6'] = '9';
        m['9'] = '6';
        m['8'] = '8';
        m['0'] = '0';
    }
    
    vector<string> findStrobogrammatic(int n) {
        return process(n,1);
    }
    
    vector<string> process(int n, int first)
    {
        vector<string> ans;
        if(n == 0){
            ans.push_back("");
            return ans;
        }
        if(n == 1)
        {
            ans.push_back("1");
            ans.push_back("8");
            ans.push_back("0");
            return ans;
        }
        if(first){
            first = 0;
            vector<string> ret = process(n-2, first);
            for(int i = 0; i < ret.size(); i++)
            {
                for(auto iter = m.begin(); iter != m.end(); iter++)
                {
                    if(iter->first == '0')continue;
                    string tmp = iter->first + ret[i] + iter->second;
                    ans.push_back(tmp);
                }
            }
            return ans;
        }else{
            vector<string> ret = process(n-2, first);
            for(int i = 0; i < ret.size(); i++)
            {
                for(auto iter = m.begin(); iter != m.end(); iter++)
                {
                    string tmp = iter->first + ret[i] + iter->second;
                    ans.push_back(tmp);
                }
            }
            return ans;
        }
    }
};