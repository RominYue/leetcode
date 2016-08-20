class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxheap.empty() || num >= maxheap.top())maxheap.push(num);
        else minheap.push(num);
        
        if(maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        
        if(minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(minheap.size() == maxheap.size())return (minheap.top() + maxheap.top())/2.0;
        if(minheap.size() > maxheap.size())return minheap.top();
        return maxheap.top();
    }
private:
    priority_queue<int> minheap;
    priority_queue<int, vector<int>, greater<int> > maxheap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();