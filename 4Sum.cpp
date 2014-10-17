class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        
        vector<vector<int> > ans;

        sort(num.begin(),num.end());

        int len = num.size();
        for(int i = 0; i < len - 3; i++)
        {
            if(i > 0 && num[i] == num[i-1]) continue;
            for(int j = i + 1; j < len - 2; j++)
            {
                if(j > i + 1 && num[j] == num[j-1])continue;
                for(int k = j + 1, p = len - 1; k < p;)
                {
                    if(k > j + 1 && num[k] == num[k-1])
                    {
                        k ++;
                        continue;
                    }
                    int tmp = num[k] + num[p] + num[j] + num[i];
                    if(tmp == target)
                    {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[k]);
                        v.push_back(num[p]);
                        ans.push_back(v);
                        k++;
                        continue;
                    }
                    else if(tmp < target)k++;
                    else p--;
                }
            }
        }
        return ans;
    }
};
