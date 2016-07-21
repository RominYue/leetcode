/*
对长数列做hash map 的存储
对短数列做扫描

时间复杂度O(len1 + len2)
空间复杂度O(len2)
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if(len1 <= len2)
        {
            return process(nums1, len1, nums2, len2);
        }
        else{
            return process(nums2, len2, nums1, len1);
        }
    }
    
    vector<int> process(vector<int>& a, int lena, vector<int>& b, int lenb)
    {
        vector<int> ans;
        map<int, int> m;
        for(int i = 0; i < lenb; i++)m[b[i]]++;
        
        for(int i = 0; i < lena; i++)
        {
            map<int,int>::iterator iter = m.find(a[i]);
            if(iter == m.end())continue;
            iter->second --;
            ans.push_back(a[i]);
            if(iter->second == 0){
                m.erase(iter);
            }
        }
        
        return ans;
    }
};