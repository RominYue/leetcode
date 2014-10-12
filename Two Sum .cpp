class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int len = numbers.size();
        vector< pair<int,int> > v;
        for(int i=0;i<len;i++)
        {
           v.push_back(make_pair(numbers[i],i+1));
        }
        sort(v.begin(),v.end());
        int posa = 0,posb = 0;
        vector<int> vec;
        bool ok = false;
        for(int i = 0; i<len; i++)
        {
            posa = v[i].second;
            int diff = target - v[i].first;
            int left = 0,right = len-1,mid;
            while(left <= right)
            {
                mid = (left + right)/2;
                if(v[mid].first == diff)
                {
                    if(i != mid)
                    {
                        posb = v[mid].second;
                        ok = true;
                    }
                    break;
                }
                else if(diff < v[mid].first)right = mid - 1;
                else left = mid + 1;
            }
            if(ok)break;
        }
        if(posa > posb){int t = posa;posa=posb;posb=t;}
        vec.push_back(posa);
        vec.push_back(posb);
        return vec;
    }
};
