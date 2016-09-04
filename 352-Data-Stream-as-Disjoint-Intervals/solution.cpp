/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        if(v.size() == 0)
        {
            v.push_back(Interval(val,val));
            return;
        }
        //0 no change
        //1 insert
        //2 delete
        int modified = 1;
        int i = 0;
        for(i = 0; i < v.size(); i++)
        {
            if(val >= v[i].start && val <= v[i].end){
                modified = 0;
                break;
            }else if(val < v[i].start){

                if(val == v[i].start - 1)
                {
                    if(i > 0 && val == v[i-1].end + 1){
                        v[i-1].end = v[i].end;
                        modified = 2;
                        break;
                    }else{
                        modified = 0;
                        v[i].start -= 1;
                        break;
                    }
                }else{
                    if(i > 0 && val == v[i-1].end + 1)
                    {
                        modified = 0;
                        v[i-1].end += 1;
                        break;
                    }else{
                        modified = 1;
                        break;
                    }
                }
            }else if(val > v[i].end){
                if(i == v.size()-1 && val == v[i].end + 1){
                    modified = 0;
                    v[i].end = val;
                }
            }
        }
        if(modified == 0)return;
        if(modified == 1)
        {
            if(i == v.size())v.push_back(Interval(val,val));
            else v.insert(v.begin() + i, Interval(val,val));
            return;
        }
        v.erase(v.begin() + i);
    }

    vector<Interval> getIntervals() {
        return v;
    }
private:
    vector<Interval> v;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */