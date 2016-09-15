/*
应该可以优化，只用常量空间，分别记录队列长度，上次的值，以及移除的值
*/
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        q.clear();
        this->size = size;
    }
    
    double next(int val) {
        if(q.empty())
        {
            q.push_back(val);
            return val;
        }else{
            if(q.size() == size)
            {
                q.pop_front();
            }
            q.push_back(val);
            
            double sum = 0;
            for(auto iter = q.begin(); iter != q.end(); iter++)
            {
                sum += *iter;
            }
            return sum / q.size();
        }
        
    }
private:
    deque<int> q;
    int size;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */