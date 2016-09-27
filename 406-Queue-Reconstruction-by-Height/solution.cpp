class Solution {
public:
    typedef pair<int,int> Node;
    vector<int> c;
    int n;
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int len = people.size();
        vector<Node> ans(len);
        vector<int> tmp(len+2,0);
        c = tmp;
        n = len;
        
        for(int i = 1; i <= n; i++)update(i,1);
        sort(people.begin(), people.end());
        
        int pre = -1;
        vector<int> preNum;
        
        for(int i = 0; i < len; i++)
        {
            if(people[i].first != pre)
            {
                for(int j = 0; j < preNum.size(); j++)update(preNum[j],-1);
                preNum.clear();
                    
            }
            int num = findKth(people[i].second+1);
            ans[num-1] = people[i];
            
            preNum.push_back(num);
            pre = people[i].first;
        }
        
        return ans;
        
    }
    
    void update(int idx, int val)
    {
        while(idx <= n)
        {
            c[idx] += val;
            idx += idx & -idx;
        }
    }
    
    int getsum(int idx)
    {
        int sum = 0;
        while(idx > 0)
        {
            sum += c[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    
    int findKth(int k)
    {
        int l = 1, r = n, mid;
        while(l <= r)
        {
            mid = (l + r) >> 1;
            if(getsum(mid) >= k)r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
    
    bool static cmp(Node a, Node b)
    {
        if(a.first == b.first)return a.second < b.second;
        return a.first < b.first;
    }
};