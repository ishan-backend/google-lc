class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // DP
        if(nums.size() == 0) return 0;
        int maxTillNow = nums[0];
        int minTillNow = nums[0];
        int ans = maxTillNow;

        for(int i=1; i<nums.size(); i++) {
            int curr = nums[i];
            int newMinTillNow = min(curr, min(maxTillNow*curr, minTillNow*curr));
            int newMaxTillNow = max(curr, max(maxTillNow*curr, minTillNow*curr));

            maxTillNow = newMaxTillNow;
            minTillNow = newMinTillNow;
            ans = max(ans, maxTillNow);
        }

        return ans;
    }
};