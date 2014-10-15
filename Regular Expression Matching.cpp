class Solution {
public:
    bool matchfirst(const char *s, const char *p)
    {
        return (*s == *p || (*p == '.' && *s != '\0'));
    }
    bool isMatch(const char *s, const char *p) {

        //empty , recursion boundary
        if(*p == '\0') return *s == '\0';

        if(*(p+1) != '*')
        {
            if(!matchfirst(s,p)) return false;
            else return isMatch(s + 1, p + 1);
        }
        else
        {
            // 0 match
            if(isMatch(s,p+2)) return true;
            //all possible match, a*
            while(matchfirst(s,p))
            {
                if(isMatch(++s,p + 2))return true;
            }
        }

        return false;
    }
};
