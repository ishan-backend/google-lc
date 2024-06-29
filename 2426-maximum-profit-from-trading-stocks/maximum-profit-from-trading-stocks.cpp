class Solution {
public:
    vector<vector<int>> dp;

    int rec(vector<int> &pre, vector<int> &fut, int b, int i) {
        if(i == fut.size()) return 0;
        if(dp[i][b] != -1) return dp[i][b];

        int dontTake = rec(pre, fut, b, i+1);
        int take = 0;
        if(fut[i] > pre[i] and b-pre[i] >= 0) {
            take = (fut[i]-pre[i]) + rec(pre, fut, b-pre[i], i+1);
        }
        return dp[i][b] = max(take, dontTake);
    }

    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        dp.resize(present.size(), vector<int>(budget+1, -1));
        return rec(present, future, budget, 0);
    }
};