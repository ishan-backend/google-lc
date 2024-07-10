class Solution {
public:

    void doOrOp(vector<int>& bc, int& orVal, int n) {
        orVal = (orVal | n);
        for(int t=0; t<32; t++)
            bc[t] += (n & (1<<t))?1:0;
    }

    void nullOr(vector<int>& bc, int& orVal, int n) {
        for(int t=0; t<32; t++) {
            bc[t] += (n & (1<<t))?-1:0; // reduce count/occurence of this set bit

            if(bc[t] == 0) {
                orVal = orVal & (~(1<<t)); // unset t'th bit in orVal
            }
        }
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        // https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/solutions/4947374/explained-two-pointer-approach-very-simple/

        int ans = INT_MAX;
        int orVal = 0;
        vector<int> bc(32, 0);
        for(int r=0, l=0; r<nums.size(); r++) {
            doOrOp(bc, orVal, nums[r]);
            if(orVal < k) continue;

            for(; l <= r and orVal >= k; l++) {
                nullOr(bc, orVal, nums[l]);
                ans = min(ans, r-l+1);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};