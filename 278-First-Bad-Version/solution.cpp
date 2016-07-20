// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int mid = 0;
        while(left <= right)
        {
            mid = left + (right-left)/2;
            bool flag = isBadVersion(mid);
            if(flag) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};