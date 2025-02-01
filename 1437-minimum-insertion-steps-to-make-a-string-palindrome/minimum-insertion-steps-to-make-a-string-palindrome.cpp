class Solution {
public:
    int minInsertions(string s) {
        // mamba -> r= abmam -> we can check if any char is diff, we can append to either i+1 index or i in either string to make palindrom
        // find lc subsequence between s and reverse s and substract from total length to find char diffs, those same no of chars need to be inserted

        string rs = s;
        reverse(rs.begin(), rs.end());
        int n = s.length();
        int dp[n+2][n+2];
        memset(dp, 0, sizeof(dp));
        // ith index in s and jth index in rs, what is maximum lcs length
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(s[i] == rs[j]) {
                    dp[i+1][j+1] = 1 + dp[i][j]; 
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]); 
                }
            }
        }

        int lcs = dp[n][n];
        return s.length() - lcs;
    }
};