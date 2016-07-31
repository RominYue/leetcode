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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0 ; i < word.size(); i++)
        {
            int id = word[i] - 'a';
            if(cur->links[id] == nullptr)
            {
                TrieNode* tmp = new TrieNode(0, word[i]);
                cur->links[id] = tmp;
            }
            cur = cur->links[id];
        }
        cur->flag++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++)
        {
            int id = word[i] - 'a';
            if(cur->links[id] == nullptr)
            {
                return false;
            }
            cur = cur->links[id];
        }
        if(cur->flag > 0)return true;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            int id = prefix[i] - 'a';
            if(cur->links[id] == nullptr)
            {
                return false;
            }
            cur = cur->links[id];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");