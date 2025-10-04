class Solution {
public:
    int dp[2001];
    bool ispalindrome(int i, int j, string& s) {
        if (i >= j)
            return true;
        while (j > i) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, int j, string& s) {
        if (i == j || ispalindrome(i, j, s))
            return 0;
        int ans = INT_MAX;

        if (dp[i] != -1)
            return dp[i]; // Return if already computed

        for (int k = i; k < j; k++) {
            int tempans;
            if (ispalindrome(i, k, s)) {
                tempans = 1 + solve(k + 1, j, s);
            }
            ans = min(ans, tempans);
        }
        return dp[i] = ans;
    }

    int minCut(string s) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return solve(0, s.size() - 1, s);
    }
};