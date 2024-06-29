class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        int n = bd.size();
        if(1LL*k*m > n)
            return -1; 
        
        // how to identify - if on x day, how many bouquets can be made?
        int lo = 1, hi = 1e9;
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;

            // check if we wait mid days
            // if m bou of k adjacent flowers can be made
            int totalb = 0;
            int curf = 0;
            for(int i=0; i<n; i++) {
                if(bd[i] > mid) {
                    curf = 0;
                } else {
                    curf++;
                    if(curf >= k) {
                        totalb++;
                        curf = 0;
                    }
                }
            }

            // if waiting for mid days, total bouquet < m, probably we need to wait more
            if(totalb < m) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};