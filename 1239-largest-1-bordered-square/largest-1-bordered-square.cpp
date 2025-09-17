class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        // horizontal and vertical prefix sums
        vector<vector<int>> hor(n, vector<int>(m, 0)), ver(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    hor[i][j] = (j == 0 ? 1 : hor[i][j-1]+1);
                    ver[i][j] = (i == 0 ? 1 : ver[i-1][j]+1);
                }
            }
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int smallside = min(hor[i][j], ver[i][j]); 
                // check if square exists with 'small' length , it can be possible from [1, small] but start from small as it is largest value and can check upto current ans which would be lesser than smallside
                while(smallside > ans) {
                    // top left corner
                    if(hor[i-smallside+1][j] >= smallside and ver[i][j-smallside+1] >= smallside)
                        ans = smallside;
                    smallside--;
                }
            }
        }

        return ans*ans;
    }
};