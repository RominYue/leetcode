/*
F(k) 与 f(k-1) 之间有递推关系
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int candidate = 0;
        int max_val = 0;
        int n = A.size();
        for(int i = 0; i < n; i++)
        {
            sum += A[i];
            candidate += i * A[i];
        }
        
        max_val = candidate;
        
        for(int i = n-1; i >= 0; i--)
        {
            candidate = candidate + sum - n * A[i];
            max_val = max(max_val, candidate);
        }
        
        return max_val;
    }
};