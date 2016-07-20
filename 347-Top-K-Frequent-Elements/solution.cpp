class Solution {
public:
    struct Node
    {
        int val;
        int freq;
        bool operator < (Node a) const
        {
            return freq <= a.freq;
        }
        bool operator > (Node a) const
        {
            return freq > a.freq;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int len = nums.size();
        if(len == 0)return ans;
        
        map<int,int> m;
        for(int i = 0; i<len; i++)m[nums[i]]++;
        
        priority_queue<Node> pq;
        map<int,int>::iterator it;
        for(it = m.begin(); it != m.end(); it++)
        {
            Node node;
            node.val = it->first;
            node.freq = it->second;
            pq.push(node);
        }
        
        int cnt = 0;
        while(!pq.empty())
        {
            if(cnt == k)break;
            Node x = pq.top();
            pq.pop();
            ans.push_back(x.val);
            cnt += 1;
        }
        
        return ans;
    }
};