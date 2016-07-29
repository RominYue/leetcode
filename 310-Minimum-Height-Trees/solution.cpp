class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        if(n == 1)
        {
            ans.push_back(0);
            return ans;
        }
        vector<int> G[n];
        vector<int> out(n);
        build_graph(G, edges, out);
        
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(out[i] == 1)q.push(i);
        }
        int cnt = 0;
        while(!q.empty())
        {
            if(cnt == n-1)
            {
                ans.push_back(q.front());
                q.pop();
                break;
            }
            if(cnt == n-2)
            {
                ans.push_back(q.front());
                q.pop();
                ans.push_back(q.front());
                q.pop();
                break;
            }
            queue<int> tmp;

            while(!q.empty())
            {
                int x = q.front();
                q.pop();
                cnt ++;
                for(int i = 0; i < G[x].size(); i++)
                {
                    out[G[x][i]]--;
                    if(out[G[x][i]] == 1)
                    {
                        tmp.push(G[x][i]);
                    }
                }
            }
            q = tmp;
        }
        return ans;
        
    }
    
    void build_graph(vector<int> G[], vector<pair<int, int>>& edges, vector<int>& out)
    {
        for(int i = 0; i < edges.size(); i++)
        {
            int to = edges[i].first;
            int from = edges[i].second;
            G[from].push_back(to);
            G[to].push_back(from);
            out[from]++;
            out[to]++;
        }
    }
};