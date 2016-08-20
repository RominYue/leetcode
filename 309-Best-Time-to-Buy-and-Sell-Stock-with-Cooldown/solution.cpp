class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || n == 1)return 0;

        int sell[n];
        int buy[n];
        int cold[n];

        sell[0] = INT_MIN;
        buy[0] = -prices[0];
        cold[0] = 0;

        for(int i = 1; i < n; i++)
        {
            cold[i] = max(cold[i-1], sell[i-1]);
            buy[i] = max(buy[i-1], cold[i-1] - prices[i]);
            sell[i] = buy[i-1] + prices[i];
        }

        return max(cold[n-1], sell[n-1]);
    }
};