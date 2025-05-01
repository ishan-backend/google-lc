class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1e6, mid, sum;
        while(lo < hi) {
            mid = (lo+hi)/2;
            sum = 0;
            for(int i: nums) {
                sum += ((i+mid-1)/mid); // ceil krna h after mid division
            }
            if(sum > threshold) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};