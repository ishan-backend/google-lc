class Solution {
public:

    int shipWithinDays(vector<int>& weights, int days) {
        const int inf = 5e7;
        int lo = 0, hi = inf;
        for(auto w: weights) {
            lo = max(lo, w);
        }

        while(lo < hi) {
            int mid = lo + (hi-lo)/2;

            // assume mid is maxm weight carried by ship each day
            // check if in days/tri[s], all weight can be taken
            // if yes this may be answer, check for lower range
            // else check in higher range
            int curw = 0;
            int needs = 1;
            for(auto w: weights) {
                if(curw+w > mid) {
                    needs++;
                    curw = 0;
                }

                curw += w;
            }

            // if on carrying mid weight, total trips > D -> increase the weight carrying cap
            if(needs > days)
                lo = mid+1;
            else
                hi = mid;
        }

        return lo;
    }
};