class Solution {
public:
    map<char, int> m;
    stack<char> st;
    void init()
    {
        m['('] = 1; m[')'] = -1;
        m['['] = 2; m[']'] = -2;
        m['{'] = 3; m['}'] = -3;
    }
    bool isValid(string s) {

        init();
        for(int i = 0; i < s.size(); i++)
        {
            if(!st.empty())
            {
                if(m[s[i]] > 0)st.push(s[i]);
                else if(m[s[i]] + m[st.top()] == 0)st.pop();
                else return false;
            }
            else
            {
                if(m[s[i]] < 0)return false;
                else st.push(s[i]);
            }
        }
        if(!st.empty())return false;
        return true;
    }
};
