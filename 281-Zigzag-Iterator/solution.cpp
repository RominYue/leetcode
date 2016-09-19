class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        i = j = 0;
        this->v1 = v1;
        this->v2 = v2;
    }

    int next() {
        if(i < v1.size() && j < v2.size())
        {
            if(i == j)return v1[i++];
            else if(i > j)return v2[j++];
            
        }else if(i < v1.size()){
            return v1[i++];
        }else{
            return v2[j++];
        }
        return 0;
    }

    bool hasNext() {
        return i < v1.size() || j < v2.size();
    }
private:
    vector<int> v1,v2;
    int i,j;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */