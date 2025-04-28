class Solution {
public:

    const int MOD = 1e9+7;
    string moves[12] = { 
        "123",
        "132",
        "121",
        "131",
        "213",
        "231",
        "232",
        "212",
        "312",
        "321",
        "313",
        "323",
    };

    vector<vector<int>> dp;

    int rec(int n, int lastMoveIdx) {
        if (n == 0) return 1;
        if (dp[n][lastMoveIdx] != -1) return dp[n][lastMoveIdx];

        int ans = 0;
        string last = moves[lastMoveIdx];

        for (int i = 0; i < 12; i++) {
            string move = moves[i];
            bool valid = true;
            for (int j = 0; j < 3; j++) {
                if (move[j] == last[j]) { // compare new move j with last 
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans = (ans + rec(n - 1, i)) % MOD;
            }
        }

        return dp[n][lastMoveIdx] = ans;
    }

    int numOfWays(int n) {
        dp.resize(n + 1, vector<int>(12, -1));
        int ans = 0;
        for (int i = 0; i < 12; i++) {
            ans = (ans + rec(n - 1, i)) % MOD;
        }
        return ans;
    }
};