/*有常数空间复杂度的解法。Math Only
*/
class Solution {
public:
    struct State{
        int val;
        int step;
        State(int a, int b):val(a),step(b){};
    };
    int integerReplacement(int n) {
        if(n == 0)return 0;
        if(n == INT_MAX)return 32;
        queue<State> q;
        q.push(State(n,0));
        int ans = 0;
        while(!q.empty())
        {
            State s = q.front();
            q.pop();
            if(s.val == 1)
            {
                ans = s.step;
                break;
            }
            if(s.val&1)
            {
                q.push(State(s.val+1, s.step+1));
                q.push(State(s.val-1, s.step+1));
            }
            else{
                q.push(State(s.val/2, s.step+1));
            }
        }
        return ans;
    }
};