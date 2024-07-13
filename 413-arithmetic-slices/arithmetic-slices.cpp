class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        vector<int> dp(n, 0);
        // subarray question with dp
        if(nums[2]-nums[1] == nums[1]-nums[0]) dp[2] = 1;
        int ans = dp[2];

        for(int i=3; i<n; i++) {
            // arithmetic slice has exactly len 3
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp[i] = dp[i-1]+1; // 1 new brand new arithmetic seq
            }

            ans += dp[i];
        }

        return ans;
    }
};