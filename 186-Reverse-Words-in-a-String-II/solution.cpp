class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size();
        if(len == 0)return;
        
        reverse(s.begin(), s.end());
        
        for(int i = 0; i < len; i++)
        {
            if(s[i] != ' ')
            {
                int j = i;
                while(j < len && s[j] != ' ')j++;
                j--;
                int tmp = j;
                while(i < j)swap(s[i++],s[j--]);
                i = tmp;
            }
        }
    }
};