/*
Tree Definition
1. n-1 条边
2. 连通图
3. 无环（满足前2个条件，第3个条件也满足）
*/
class Solution {
public:
    
    vector<int> fa;
    int count;
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size() != n-1)return false;
        vector<int> tmp(n,0);
        fa = tmp;
        count = n;
        
        for(int i = 0; i < n; i++)fa[i] = i;
        
        for(int i = 0; i < edges.size(); i++)
        {
            int v1 = edges[i].first;
            int v2 = edges[i].second;
            union_op(v1, v2);
        }
        
        return count == 1;
    }
    
    void union_op(int a, int b)
    {
        int roota = find(a);
        int rootb = find(b);
        if(roota == rootb)return;
        fa[roota] = rootb;
        count--;
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
};