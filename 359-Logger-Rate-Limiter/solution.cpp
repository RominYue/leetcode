/*
没有考虑expire过期之后，删除对应message的问题
*/
class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> m;
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message) == m.end())
        {
            m[message] = timestamp;
            return true;
        }else{
            if(timestamp - m[message] >= 10)
            {
                m[message] = timestamp;
                return true;
            }
            return false;
        }
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */