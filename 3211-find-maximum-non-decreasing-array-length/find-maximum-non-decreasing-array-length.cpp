class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        vector<long long> ps(n+1, 0);
        for(int i=1; i<=n; i++) {
            ps[i] = ps[i-1] + nums[i-1]; // 1 index based prefix sum
        }

        vector<int> pre(n+2); // BS end() support ahead of 1 based indexing
        int i=0; // initially 0, we will be playing on 1 index
        for(int j=1; j<=n; j++) {
            // When reaching the setted k!!!
            i = max(i, pre[j]); // handles cases when we are at some index in between the desired subarray i = max(i [previously set], 0)
            dp[j] = dp[i] + 1;


            // Setting k ahead !!!
            // IMP!! i < j; and if j is the end index of prev subarray, then for next high sum subarray the last index idx will be stored in pre array
            int idx = lower_bound(ps.begin(), ps.end(), 2*ps[j] - ps[i]) - ps.begin();
            pre[idx] = j; // for index
        }

        return dp[n];
    }
};