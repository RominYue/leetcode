class Solution {
public:
    string s[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string original;
    int n;
    void dfs(int len,string str)
    {
        if(len == n)
        {
            ans.push_back(str);
            return;
        }
        int tmp = original[len] - '0';
        for(int i = 0; i < s[tmp].size(); i++)
        {
            dfs(len + 1, str + s[tmp][i]);
        }
    }
    vector<string> letterCombinations(string digits) {

        original = digits;
        n = digits.size();
        dfs(0,"");
        return ans;
    }
};
