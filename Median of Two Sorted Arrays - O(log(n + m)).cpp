class Solution {
public:
        double findKthNum(int a[], int m, int b[], int n, int k)
        {
            if(m > n) return findKthNum(b,n,a,m,k);
            
            //recursion boudaries
            if(m == 0)return b[k-1];
            if(k == 1)return min(a[0],b[0]);
            
            //divided into two parts
            int pa = min(k/2 , m), pb = k - pa;
            if(a[pa - 1] < b[pb - 1])return findKthNum(a + pa, m-pa,b,n,k - pa);
            else if(a[pa- 1] > b[pb - 1])return findKthNum(a,m,b +pb,n - pb,k - pb);
            else return a[pa - 1];
        }
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            int sum = m + n;
            if((m +n) & 1) return findKthNum(A,m,B,n, sum/2 + 1);
            else return (findKthNum(A,m,B,n,sum/2) +findKthNum(A,m,B,n,sum/2 +1))/2.0;
        }
};
