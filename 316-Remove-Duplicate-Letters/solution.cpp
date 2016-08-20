class Solution {
public:
    string removeDuplicateLetters(string s) {
        int hash[26];
        int visit[26];
        memset(hash,0,sizeof(hash));
        memset(visit,0,sizeof(visit));
        stack<char> st;
        for(int i = 0; i < s.size(); i++)hash[s[i] - 'a']++;
        
        for(int i = 0; i < s.size(); i++)
        {
            int idx = s[i] - 'a';
            if(visit[idx] == 1)
            {
                hash[idx]--;
                continue;
            }
            if(!st.empty())
            {
                while(!st.empty() && s[i] < st.top() && hash[st.top() - 'a'] > 0)
                {
                    //cout<<st.top()<<" "<< hash[st.top() - 'a'] <<endl;
                    visit[st.top() - 'a'] = 0;
                    st.pop();
                }
            }
            //cout<<s[i]<<endl;
            st.push(s[i]);
            visit[idx] = 1;
            hash[idx]--;
        }
        
        string ans;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        string ret;
        for(int i = ans.size() - 1; i >= 0; i--)ret += ans[i];
        return ret;
    }
};