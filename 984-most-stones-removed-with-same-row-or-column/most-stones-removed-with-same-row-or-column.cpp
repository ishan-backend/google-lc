class Solution {
public:

    int find(vector<int> &par, int x) {
        while(par[x] != x)
            x = par[x];
        return x;
    }

    void merge(vector<int> &par, int i, int j, int &tc) {
        int p1 = find(par, i);
        int p2 = find(par, j);
        if(p1 != p2) {
            par[p1] = p2;
            tc--;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        // matching rows and columns ko same set me dalo
        int n = stones.size();
        vector<int> par(n);
        for(int i=0; i<n; i++) par[i] = i;
        int tc = n;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1])
                merge(par, i, j, tc);
            }
        }

        return n-tc;
    }
};