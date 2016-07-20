class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area1 = (D-B)*(C-A);
        long long area2 = (H-F)*(G-E);
        long long y = (long long)min(D,H) - max(B,F);
        long long x = (long long)min(C,G) - max(A,E);
        if(y < 0) y = 0;
        if(x < 0) x = 0;
        return area1 + area2 - x*y;
    }
};