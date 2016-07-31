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

    TrieNode* getRoot(){
        return root;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    Trie trie;
    int n,m;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        set<string> ans_set;
        if(words.size() == 0)return ans;
        m = board.size();
        if(m == 0)return ans;
        n = board[0].size();
        //build Trie Tree
        for(int i = 0; i < words.size(); i++)
        {
            trie.insert(words[i]);
        }
        //DFS search to find and tune
        TrieNode* root = trie.getRoot();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                string s = "";
                dfs(i,j,root,s,ans_set,board);
            }
        }
        set<string> ::iterator iter;
        for(iter = ans_set.begin(); iter != ans_set.end(); iter ++)
        {
            ans.push_back(*iter);
        }
        return ans;
    }

    void dfs(int x, int y, TrieNode* cur, string ret, set<string>& ans_set, vector<vector<char>>& board)
    {
        if(cur->flag > 0)
        {
            ans_set.insert(ret);
        }
        if(!check(x,y, board))return;

        int id = board[x][y] - 'a';
        if(cur->links[id] == nullptr)return;

        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            char tmp = board[x][y];
            board[x][y] = '#';
            dfs(next_x, next_y, cur->links[id], ret + tmp, ans_set, board);
            board[x][y] = tmp;
        }
    }

    bool check(int x,int y, vector<vector<char>>& board)
    {
        if(x < m && x >= 0 && y < n && y >= 0 && board[x][y] != '#')return true;
        return false;
    }
};