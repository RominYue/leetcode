class TrieNode {
public:
    // Initialize your data structure here.
    int flag;
    char ch;
    TrieNode* links[26];
    TrieNode() {
        for(int i = 0 ; i < 26; i++)links[i] = nullptr;
    }

    TrieNode(int flag, char ch){
        this->flag = flag;
        this->ch = ch;
        for(int i = 0 ; i < 26; i++)links[i] = nullptr;
    }
};

class WordDictionary {
public:
    WordDictionary(){
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0 ; i < word.size(); i++)
        {
            int id = word[i] - 'a';
            if(cur->links[id] == nullptr)
            {
                TrieNode* tmp = new TrieNode(0, word[i]);
                cur->links[id] = tmp;
                delete(tmp);
            }
            cur = cur->links[id];
        }
        cur->flag++;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode* cur = root;
        int ans = 0;
        dfs_search(root, word, 0, ans);
        if(ans)return true;
        return false;
    }

    void dfs_search(TrieNode* cur, string word, int len, int& ans)
    {
        if(cur->flag > 0 && len == word.size())
        {
            ans = 1;
            return;
        }
        if(len == word.size())return;
        if(word[len] == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(cur->links[i] == nullptr)continue;
                dfs_search(cur->links[i], word, len+1, ans);
            }
        }
        int id = word[len] - 'a';
        if(cur->links[id] == nullptr)return;
        dfs_search(cur->links[id], word, len+1, ans);
    }

private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");