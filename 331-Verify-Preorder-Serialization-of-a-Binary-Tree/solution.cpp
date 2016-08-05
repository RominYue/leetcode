class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
        if(len == 0)return true;
        if(len == 1 && preorder[0] == '#')return true;
        stack<int> s;
        bool first = true;
        for(int i = 0; i < len; i++)
        {
            if(preorder[i] == ',')continue;
            if(!s.empty())
            {
                s.top()++;
                if(preorder[i] == '#')
                {
                    while(!s.empty() && s.top() == 2)
                    {
                        s.pop();
                    }
                }
                else{
                    s.push(0);
                    while(isdigit(preorder[i]))i++;
                    i--;
                }
            }
            else
            {
                if(!first)return false;
                first = false;
                if(preorder[i] == '#')return false;
                s.push(0);
                while(isdigit(preorder[i]))i++;
                i--;
            }
        }
        if(!s.empty())return false;
        return true;
    }
};
