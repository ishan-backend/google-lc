class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        int n = s.size();
        
        vector<vector<int>> dp(n+1, vector<int> (n, 0)); //max length lps till length i and start at j
        
        for(int i=0; i<n; i++) dp[1][i] = 1;
        
        //length
        for(int i=2; i<=n; i++)
        {
            
            //startoff
            for(int j=0; j<=n-i; j++)
            {
                
                if(s[j] == s[j+i-1])
                {
                    dp[i][j] = 2 + dp[i-2][j+1];
                }
                else
                {
                    //for two ends: for left end(if right end is inored and recursed): i-1 length and starts at j
                    // for right end (if left end is ignored, and recursed): i-1 length and starts at j+1
                    dp[i][j] = max(dp[i-1][j+1], dp[i-1][j]);
                }
                
            }
            
        }
        
        return dp[n][0];
        
    }
};