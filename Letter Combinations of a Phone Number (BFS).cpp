class Solution {
public:
    string s[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        ans.push_back("");
        for(int i = 0; i < digits.size(); i++)
        {
            vector<string> tmpans;
            for(int j = 0; j < ans.size(); j ++)
            {
                int id = digits[i] - '0';
                for(int k = 0; k < s[id].size(); k++)
                {
                    tmpans.push_back(ans[j] + s[id][k]);
                }
            }
            ans = tmpans;
        }
        return ans;
    }
};
