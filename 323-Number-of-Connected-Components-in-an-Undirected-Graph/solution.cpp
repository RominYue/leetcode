class Solution {
public:
    vector<int> fa;
    int cnt;
    int count;
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> tmp(n, 0);
        fa = tmp;
        
        count = n;
        init();
        cnt = n;
        for(int i = 0; i < edges.size(); i++)
        {
            union_op(edges[i].first, edges[i].second);
        }
        return cnt;
    }
    
    void init()
    {
        for(int i = 0; i < count; i++)
            fa[i] = i;
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
    
    void union_op(int p, int q)
    {
        int a = find(p);
        int b = find(q);
        if(a == b)return;
        fa[a] = b;
        cnt--;
    }
};