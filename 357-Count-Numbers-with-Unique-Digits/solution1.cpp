class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)return 1;
        if(n == 1)return 10;
        int sum = 10;
        int product = 9;
        for(int k = 2; k <= n; k++)
        {
            product = product * (9- k + 2);
            sum += product;
        }
        return sum;
    }
};