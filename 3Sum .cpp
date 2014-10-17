class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

        vector<vector<int> > ans;

        sort(num.begin(),num.end());

        int len = num.size();
        for(int i = 0; i < len - 2; i++)
        {
            //we have discussed num[i-1], no need to deal with num[i]
            if(i > 0 && num[i] == num[i-1])continue;

            for(int j = i + 1, k = len - 1; j < k;)
            {
                //same with num[i] == num[i-1]
                if(j > i + 1 && num[j] == num[j-1])
                {
                   j++;
                   continue;
                }
                int tmp = num[j] + num[k] + num[i];
                if(tmp == 0)
                {
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[k]);
                    ans.push_back(v);
                    j++;
                    continue;
                }
                else if(tmp < 0) j++;
                else k --;
            }
        }
        return ans;
    }
};
