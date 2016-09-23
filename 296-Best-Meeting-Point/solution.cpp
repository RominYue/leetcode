class Solution {
public:

    int minTotalDistance(vector<vector<int>>& grid) {
        
        vector<int> row, col;
        int m = grid.size();
        if(m == 0)return 0;
        
        int n = grid[0].size();
        if(n == 0)return 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        sort(col.begin(), col.end());
        
        int max_x = row[row.size()/2];
        int max_y = col[col.size()/2];
        
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    ans += abs(i - max_x) + abs(j - max_y);
            }
        }
        return ans;
    }
};