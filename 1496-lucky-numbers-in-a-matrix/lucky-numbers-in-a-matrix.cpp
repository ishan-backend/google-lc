class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mt) {
        int n = mt.size();
        int m = mt[0].size();
        vector<int> res;
        vector<int> minm(n), maxm(m);
        for(int i=0; i<n; i++) {
            int mn = INT_MAX;
            for(int j=0; j<m; j++) {
                mn = min(mn, mt[i][j]);
            }
            minm[i] = mn;
        }

        for(int i=0; i<m; i++) {
            int mn = INT_MIN;
            for(int j=0; j<n; j++) {
                mn = max(mn, mt[j][i]);
            }
            maxm[i] = mn;
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mt[i][j] == minm[i] and mt[i][j] == maxm[j]) {
                    ans.push_back(mt[i][j]);
                }
            }
        }

        return ans;
    }
};