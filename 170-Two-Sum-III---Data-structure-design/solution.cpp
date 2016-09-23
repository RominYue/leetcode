class TwoSum {
public:
    unordered_map<int, int> ctr;
    // Add the number to an internal data structure.
	void add(int number) {
        ctr[number]++;
    }
    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
        for (auto nc : ctr)
        if (ctr.count(value - nc.first) && (nc.first != value - nc.first || nc.second > 1))
            return true;
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);