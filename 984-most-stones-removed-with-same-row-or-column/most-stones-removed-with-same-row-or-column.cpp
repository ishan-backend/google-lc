class Solution {
public:
    int find(vector<int>& par, int x) {
        if (par[x] != x)
            par[x] = find(par, par[x]); // path compression is important for this problem for all nodes to finally to one parent node in CC
        return par[x];
    }

    void merge(vector<int>& par, int i, int j) {
        int p1 = find(par, i);
        int p2 = find(par, j);
        if (p1 != p2) {
            par[p1] = p2;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        // matching rows and columns ko same set me dalo
        int n = stones.size();
        vector<int> par(n);
        for (int i = 0; i < n; i++)
            par[i] = i;
        /*
            This is a connected components problem in disguise.
        •	If two stones are in the same row or same column, they’re connected.
        •	The entire group of connected stones can be reduced to just one stone.
        •	So if there are k connected stones → you can remove k - 1 stones.
            
            The maximum number of stones you can remove =
    Total stones − Number of connected components
        */

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]) {
                    merge(par, i, j);
                }
            }
        }

        unordered_set<int> comp;
        for(int i=0; i<n; i++) {
            comp.insert(find(par, i));
        }

        return n - comp.size();
    }
};