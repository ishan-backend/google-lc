class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Step 1: Count frequency of each number
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        // Step 2: Store unique values and sort them
        vector<int> values;
        for (auto &p : freq) values.push_back(p.first);
        sort(values.begin(), values.end());

        int n = values.size();
        vector<int> dp(n, 0);

        /*
        dp[i] = maximum points we can earn considering values[0..i]

        IMPORTANT IDEA (Delete-and-Earn → House Robber):
        ------------------------------------------------
        If we take number = x:
            - We earn x * freq[x]
            - We MUST delete (x - 1) and (x + 1)
        This is identical to:
            - Robbing a house prevents robbing adjacent houses
        Here:
            - "Adjacent houses" = consecutive numbers
        */

        // Base case
        dp[0] = values[0] * freq[values[0]];

        for (int i = 1; i < n; i++) {
            int currValue = values[i] * freq[values[i]];

            // Case 1: values[i] is consecutive to values[i-1]
            if (values[i] == values[i - 1] + 1) {

                /*
                Two choices:

                1️⃣ Take values[i]:
                   - We earn currValue
                   - We MUST skip values[i-1] (num-1 deletion)
                   - So we add dp[i-2]

                2️⃣ Skip values[i]:
                   - Best we can do is dp[i-1]

                dp[i] = max(skip, take)
                */
                int take = currValue + (i >= 2 ? dp[i - 2] : 0);
                int skip = dp[i - 1];
                dp[i] = max(take, skip);

            } 
            // Case 2: values[i] is NOT consecutive
            else {
                /*
                No conflict:
                - Taking values[i] does NOT delete anything useful
                - Safe to add it to previous result
                */
                dp[i] = dp[i - 1] + currValue;
            }
        }

        return dp[n - 1];
    }
};