class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> left(m, 0), right(m, m), height(m, 0); // keeps data from previous row to be updated in current row
        int ans = 0;
        for(int i=0; i<n; i++) {
            int cur_left = 0, cur_right = m-1;

            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else
                    height[j] = 0; // imp
            }

            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') left[j] = max(left[j], cur_left);
                else {
                    left[j] = 0; // left wale consider mt kro
                    cur_left = j+1;
                }
            }

            for(int j=m-1; j>=0; j--) {
                if(matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else {
                    right[j] = m; // right wale consider mt kro
                    cur_right = j-1;
                }
            }

            for(int j=0; j<m; j++) {
                ans = max(ans, (right[j]-left[j]+1) * height[j]);
            }
        }

        return ans;

    }
};