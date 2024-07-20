class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // find minm of current row sum or col sum and fit it
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int minm = min(rowSum[i], colSum[j]);
                if(minm < 0)
                    continue;
                rowSum[i] -= minm;
                colSum[j] -= minm;
                res[i][j] = minm;
            }
        }

        return res;
    }
};