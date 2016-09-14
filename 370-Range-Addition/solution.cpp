/*
trick 
update range[l,r]只需要
update[l] inc , update[r+1], -inc
然后顺序累加即可
*/
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ret(length, 0);
        
        for(int i = 0; i < updates.size(); i++)
        {
            int l = updates[i][0];
            int r = updates[i][1];
            int inc = updates[i][2];
            if(l < length) ret[l] += inc;
            if(r + 1 < length) ret[r+1] -=inc;
        }
        
        int curinc = 0;
        
        for(int i = 0; i < length; i++)
        {
            int tmp = ret[i];
            ret[i] += curinc;
            curinc += tmp;
        }
        
        return ret;
    }
};