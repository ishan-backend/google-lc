class Solution {
public:
    int check(vector<int>& s, int m) {
        int cnt = 0; // maximum number of divisions possible if m is desired total sweetness by you
        int cursum = 0;
        for(auto i: s) {
            cursum += i;
            if(cursum >= m) {
                cursum = 0;
                cnt++;
            }
        }

        return cnt;
    }

    int maximizeSweetness(vector<int>& s, int k) {
        ++k;
        int lo = *min_element(s.begin(), s.end());
        int hi = accumulate(s.begin(), s.end(), 0);
        while(lo < hi) {
            int mid = (lo + hi + 1)/2;
            if(check(s, mid) >= k) {
                // agar mid se hogya to answer aur maximise krke check krskte h
                lo = mid;
            } else {
                hi = mid-1;
            }
        }

        return lo;
    }
};