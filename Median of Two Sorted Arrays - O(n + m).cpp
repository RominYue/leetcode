class Solution {
public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
                int tmp;
                sort(A , A + m);
                sort(B , B + n);
                int pointa = 0, pointb = 0, cnt = 0;
                int vala = 0, valb = 0;
                while(pointa < m && pointb < n)
                {
                        if(A[pointa] <= B[pointb])tmp = A[pointa++];
                        else tmp = B[pointb++];
                        ++ cnt;
                        if((m+n)%2 == 0)
                        {
                                if( cnt == (m+n)/2 )vala = tmp;
                                if(cnt == ((m+n)/2 + 1))valb = tmp;
                        }
                        else
                        {
                                if(cnt == (m+n)/2 + 1) vala = tmp;
                        }
                }
                while(pointa < m)
                {
                        tmp = A[pointa ++];
                        ++ cnt;
                        if((m+n) %2 == 0)
                        {
                                if( cnt == (m+n)/2 )vala = tmp;
                                 if(cnt == ((m+n)/2 + 1))valb = tmp;
                        }
                        else
                        {
                                if(cnt == (m+n)/2 + 1) vala = tmp;
                        }
                }
                while(pointb < n)
                {
                        tmp = B[pointb ++];
                        ++ cnt;
                        if((m+n)%2 == 0)
                        {
                                if( cnt == (m+n)/2 )vala = tmp;
                                if(cnt == ((m+n)/2 + 1))valb = tmp;
                        }
                        else
                        {
                                if(cnt == (m+n)/2 +1) vala = tmp;
                        }
                }
                //cout<<vala<<" "<<valb<<endl;
                if((m+n)%2 == 0) return (vala +valb)/2.0;
                else return vala;
        }
};
