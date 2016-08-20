/*
按长度层次遍历
*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        set<string> visited;
        vector<string> ans;
        if(isValid(s))
        {
            ans.push_back(s);
            return ans;
        }
        q.push(s);
        visited.insert(s);
        bool found = false;

        while(!q.empty())
        {
            string tmp = q.front();
            q.pop();
            if(isValid(tmp))
            {
                ans.push_back(tmp);
                found = true;
            }

            if(found)continue;

            for(int i = 0; i < tmp.size(); i++)
            {
                if(tmp[i] == '(' || tmp[i] == ')')
                {
                    string next_s = tmp.substr(0, i) + tmp.substr(i+1);
                    if(visited.find(next_s) == visited.end())
                    {
                        q.push(next_s);
                        visited.insert(next_s);
                    }
                }
            }
        }

        return ans;
    }

    bool isValid(string& s)
    {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')cnt++;
            else if(s[i] == ')')
            {
                cnt--;
                if(cnt < 0)return false;
            }
        }
        return cnt == 0;
    }
};