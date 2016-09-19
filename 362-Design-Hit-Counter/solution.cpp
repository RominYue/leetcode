class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        s.clear();
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        s.insert(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        auto iter = s.upper_bound(timestamp - 300);
        s.erase(s.begin(), iter);
        return s.size();
    }
private:
    multiset<int> s;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */