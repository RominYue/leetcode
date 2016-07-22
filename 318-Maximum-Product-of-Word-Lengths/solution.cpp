class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> marks(len,0);
        for(int i = 0; i < len; i++)
        {
        	for(int j = 0; j < words[i].size(); j++)
        	{
        		marks[i] |= 1 << (words[i][j] - 'a'); 
        	}
        }
        
        int max_ans = 0;
        for(int i = 0; i < len; i++)
        {
        	for(int j = i + 1; j < len; j++)
        	{
        		if((marks[i] & marks[j]) == 0)
        		{
        		    int tmp = words[i].size()*words[j].size();
        			max_ans = max(max_ans, tmp);
        		}
        	}
        }
        return max_ans;
    }
};