class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++) {
            int curTemp = nums[i];
            // maintain monotonically decreasing stack from L to R
            while(!stk.empty() and curTemp > nums[stk.top()]) {
                // previous day for which curTemp will be next warmer temp
                int prevDay = stk.top(); stk.pop();
                ans[prevDay] = i-prevDay;
            }

            stk.push(i);
        }

        return ans;
    }
};