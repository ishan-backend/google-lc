class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n]; // adj list
        vector<int> indeg(n, 0);

        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }

        queue<int> q; // BFS in topo sort
        for(int i=0; i<n; i++) {
            if(indeg[i] == 0)
                q.push(i);
        }

        set<int> par[n]; // set of every list of ancestors for every node
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(auto it: adj[cur]) {
                par[it].insert(cur);
                // also insert all parents above cur to it
                for(auto it2: par[cur]) {
                    par[it].insert(it2);
                }

                indeg[it]--;
                if(indeg[it] == 0)
                    q.push(it);
            }
        }

        // ans
        vector<vector<int>> ans(n, vector<int>());
        for(int i=0; i<n; i++) {
            ans[i] = vector<int>(par[i].begin(), par[i].end());
        }

        return ans;
    }
};