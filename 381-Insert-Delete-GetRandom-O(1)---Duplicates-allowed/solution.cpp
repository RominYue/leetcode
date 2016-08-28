class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].insert(nums.size());
        nums.push_back(val);
        return m[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(!m.count(val))return false;
        
        int index = *(m[val].begin());
        int last = nums.back();
        if(last != val)
        {
            //rest last's index
            int last = nums.back();
            m[last].erase(m[last].find(nums.size()-1));
            m[last].insert(index);
            nums[index] = last;
            //erase in map
            m[val].erase(index);
            if(m[val].empty())m.erase(val);
            //erase in array
            nums.pop_back();
        }
        else{
            m[val].erase(nums.size()-1);
            if(m[val].empty())m.erase(val);
            nums.pop_back();
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int> > m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */