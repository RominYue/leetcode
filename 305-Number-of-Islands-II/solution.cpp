class Solution {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<int> fa;
    int m,n;
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ans;
        int len = positions.size();
        if(len == 0)return ans;
        if(len == 1)
        {
            ans.push_back(1);
            return ans;
        }
        this->m = m;
        this->n = n;
        map<int,int> nodeMap;
        int num = 0;
        vector<int> tmp(len+1, 0);
        fa = tmp;
        
        for(int i = 1; i <= len; i++)fa[i] = i;
        
        for(int i = 0; i < len; i++)
        {
            int x = positions[i].first;
            int y = positions[i].second;
            nodeMap[getIdx(x,y)] = ++num;
            
            for(int j = 0; j < 4; j++)
            {
                int adj_x = x + dir[j][0];
                int adj_y = y + dir[j][1];
                if(check(adj_x, adj_y, m, n) && nodeMap.find(getIdx(adj_x, adj_y)) != nodeMap.end())
                {
                    union_set(nodeMap[getIdx(x,y)], nodeMap[getIdx(adj_x, adj_y)]);
                }
            }
            
            int cnt = 0;
            for(int i = 1; i <= num; i++)
            {
                if(fa[i] == i) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    
    int getIdx(int i, int j)
    {
        return n*i + j;
    }
    
    int find(int p)
    {
        while(p != fa[p])
        {
            fa[p] = fa[fa[p]];
            p = fa[p];
        }
        return p;
    }
    
    void union_set(int p, int q)
    {
        int a = find(p);
        int b = find(q);
        if(a == b)return;
        if(a < b)fa[b] = a;
        else fa[a] = b;
    }
    
    bool check(int x, int y, int m, int n)
    {
        if(x >= 0 && x<m && y >= 0 && y < n)return true;
        return false;
    }
};