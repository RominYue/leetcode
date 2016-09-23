class WordDistance {
public:
    
    unordered_map<string, vector<int> > m;

    WordDistance(vector<string>& words) {
        m.clear();
        for(int i = 0; i < words.size(); i++)
        {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0;
        int min_val = INT_MAX;
        
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
        return min_val;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");