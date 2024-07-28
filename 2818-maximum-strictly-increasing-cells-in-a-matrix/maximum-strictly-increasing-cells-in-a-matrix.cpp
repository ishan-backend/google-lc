class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        set<int> decNums;
        using vpii = vector<pair<int, int>>;
        map<int, vpii> valToLoc;

        vector<int> rowMax(n, 0), colMax(m, 0); 


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                valToLoc[mat[i][j]].push_back({i, j});
                decNums.insert(-mat[i][j]);
            }
        }

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(auto val: decNums) {
            for(auto &pos: valToLoc[-val]) {
                int r = pos.first;
                int c = pos.second;

                // for this r, c just check what is the maximum length path of this row and col, do +1
                dp[r][c] = max(rowMax[r], colMax[c]) + 1;
            }

            // after populating the dp[r][c] -> this would be +1 of previous values in this row or col, do update rowMax and colMax
            for(auto &pos: valToLoc[-val]) {
                int r = pos.first;
                int c = pos.second;

                rowMax[r] = max(rowMax[r], dp[r][c]);
                colMax[c] = max(colMax[c], dp[r][c]);
            }
        }

        return max(*max_element(rowMax.begin(), rowMax.end()),
            *max_element(colMax.begin(), colMax.end())
        );
    }
};