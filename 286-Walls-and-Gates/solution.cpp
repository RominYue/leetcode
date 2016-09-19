class Solution {
public:
    struct State{
        int x,y;
        int step;
    };

    int m,n;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    void wallsAndGates(vector<vector<int> >& rooms) {
        int m = rooms.size();
        if(m == 0)return;
        int n = rooms[0].size();
        if(n == 0)return;

        this->m = m;
        this->n = n;

        queue<State> q;
        State s;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(rooms[i][j] == 0)
                {
                    s.x = i;
                    s.y = j;
                    s.step = 0;
                    q.push(s);
                }
            }
        }
        
        while(!q.empty())
        {
            State tmp = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int next_x = tmp.x + dir[i][0];
                int next_y = tmp.y + dir[i][1];
                if(check(next_x, next_y) && rooms[next_x][next_y] != -1)
                {
                    if(tmp.step + 1 < rooms[next_x][next_y])
                    {
                        s.x = next_x;
                        s.y = next_y;
                        s.step = tmp.step + 1;
                        rooms[next_x][next_y] = tmp.step + 1;
                        q.push(s);
                    }
                }
            }
        }
    }

    bool check(int x,int y)
    {
        if(x >= 0 && x < m && y >= 0 && y < n)return true;
        return false;
    }
};