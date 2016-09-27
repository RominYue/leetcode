class Solution {
public:
    string toHex(int num) {
        if(num == 0)return "0";
        
        unsigned int newNum = (unsigned int)num;
        string ret;
        while(newNum > 0)
        {
            ret += num2Hex(newNum%16);
            newNum /= 16;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    char num2Hex(unsigned int num){
        char hex[] = {'0', '1', '2', '3','4','5','6','7','8','9','a','b','c','d','e','f'};
        return hex[num];
    }
};