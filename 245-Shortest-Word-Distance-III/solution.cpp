class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int> > m;
        for(int i = 0; i < words.size(); i++)
        {
            m[words[i]].push_back(i);
        }
        
        int i = 0, j = 0;
        int min_val = INT_MAX;
        
        if(word1 == word2)
        {
            for(int i = 1; i < m[word1].size(); i++)
                min_val = min(min_val, m[word1][i] - m[word1][i-1]);
        }else{
        
            while(i < m[word1].size() && j < m[word2].size())
            {
                if(m[word1][i] < m[word2][j])
                {
                    min_val = min(m[word2][j] - m[word1][i], min_val);
                    i++;
                }else{
                    min_val = min(m[word1][i] - m[word2][j], min_val);
                    j++;
                }
            }
        }
        return min_val;
    }
};