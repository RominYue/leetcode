class NumMatrix {
public:
    int n,m;
    bool empty;
    vector<vector<int> > c;
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if(m == 0){
            empty = true;
            return;
        }
        int n = matrix[0].size();
        if(n == 0){
            empty = true;
            return;
        }
        vector<vector<int> > tmp(m+3, vector<int>(n+3,0));
        c = tmp;
        this->n = n;
        this->m = m;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int num = sumRegion(row, col, row, col);
        for(int i = row+1; i <= m; i += i & -i)
        {
            for(int j = col+1; j <= n; j+= j & -j)
            {
                c[i][j] += val-num;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int area1 = (row1 - 1 < 0 || col1 -1 < 0)? 0: getsum(row1, col1);
        int area2 = row1 - 1 < 0? 0: getsum(row1, col2+1);
        int area3 = col1 - 1 < 0? 0: getsum(row2+1, col1);
        int area4 = getsum(row2+1, col2+1);
        return area4 - area2 - area3 + area1;
    }

    int getsum(int row, int col)
    {
        int sum = 0;
        for(int i = row; i >= 1; i -= i & -i)
        {
            for(int j = col; j >= 1; j -= j & -j)
                sum += c[i][j];
        }
        return sum;
    }
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);