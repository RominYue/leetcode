/*
拓扑排序，依次删除入度为0的点
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
       vector<int> G[numCourses];
       vector<int> ind(numCourses);
       build_graph(G, prerequisites,ind);
       return toplogical_sort(G, ind, numCourses);
    }
    
    void build_graph(vector<int> G[], vector<pair<int, int>>& prerequisites, vector<int>& ind)
    {
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int to = prerequisites[i].first;
            int from = prerequisites[i].second;
            G[from].push_back(to);
            ind[to]++;
        }
    }
    
    bool toplogical_sort(vector<int> G[], vector<int>& ind, int numCourses)
    {
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < numCourses; i++)
        {
            if(ind[i] == 0)q.push(i);
        }
        while(!q.empty())
        {
            int x = q.front();
            cnt ++;
            q.pop();
            for(int i = 0; i < G[x].size(); i++)
            {
                ind[G[x][i]]--;
                if(ind[G[x][i]] == 0)
                {
                    q.push(G[x][i]);
                }
            }
        }
        if(cnt == numCourses)return true;
        return false;
    }
};