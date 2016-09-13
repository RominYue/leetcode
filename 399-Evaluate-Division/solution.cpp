class Solution {
public:
    typedef pair<string, double> Node;
    unordered_map<string, vector<Node>> Graph;
    unordered_map<string, double> ret;

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        Graph.clear();
        ret.clear();
        //build graph
        for(int i = 0; i < equations.size(); i++)
        {
            string numerator = equations[i].first;
            string denominator = equations[i].second;
            Graph[numerator].push_back(make_pair(denominator, values[i]));
            if(values[i] != 0.0) Graph[denominator].push_back(make_pair(numerator, 1.0/values[i]));
        }
        //dfs get possible results
        for(auto iter = Graph.begin(); iter != Graph.end(); iter++)
        {
            set<string> vis;
            dfs(iter->first, iter->first, 1.0, vis);
        }
        //deal with query
        vector<double> ans;
        for(int i = 0; i < queries.size(); i++)
        {
            string key = queries[i].first + ' ' + queries[i].second;
            if(ret.find(key) == ret.end())ans.push_back(-1.0);
            else ans.push_back(ret[key]);
        }
        return ans;
    }

    void dfs(string start, string cur, double val, set<string>& vis)
    {
        vis.insert(cur);
        string key = start + ' ' + cur;
        if(ret.find(key) == ret.end())
        {
            ret[key] = val;
        }
        for(int i = 0; i < Graph[cur].size(); i++)
        {
            string denominator = Graph[cur][i].first;
            if(vis.find(denominator) != vis.end())continue;
            double ans = Graph[cur][i].second;
            dfs(start, denominator, val*ans, vis);
        }
    }
};