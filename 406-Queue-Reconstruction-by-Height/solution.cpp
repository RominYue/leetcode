class Solution {
public:
    typedef pair<int,int> Node;
    set<int> s;
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int len = people.size();
        s.clear();
        vector<Node> ans(len);
        
        for(int i = 0; i < len; i++)s.insert(i);
        sort(people.begin(), people.end());
        
        int pre = -1;
        vector<int> preNum;
        
        for(int i = 0; i < len; i++)
        {
            if(people[i].first != pre)
            {
                for(int j = 0; j < preNum.size(); j++)s.erase(preNum[j]);
                preNum.clear();
            }
            int num = findKth(people[i].second+1);
            //cout<<people[i].first<<" "<<people[i].second<<" "<< num << endl;
            ans[num] = people[i];
            
            preNum.push_back(num);
            pre = people[i].first;
        }
        
        return ans;
        
    }
    
    int findKth(int k)
    {
        int cnt = 1;
        for(auto iter = s.begin(); iter != s.end(); iter++)
        {
            if(cnt == k)return *iter;
            cnt++;
        }
        return 0;
    }
    
    bool static cmp(Node a, Node b)
    {
        if(a.first == b.first)return a.second < b.second;
        return a.first < b.first;
    }
};