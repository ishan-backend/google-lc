class Solution {
public:
    // checks if b will get detonated by a
    bool bomb(vector<int> a, vector<int> b) {
        // to prevent floating type comparisons
        long long dx = a[0] - b[0];
        long long dy = a[1] - b[1];
        long long r = a[2];
        return dx * dx + dy * dy <= r * r;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        // lets keep bomb number same as index
        int n = bombs.size();
        vector<vector<int>> adj(n);
        adj.clear();
        vector<int> indegree(n, 0);

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(bomb(bombs[i], bombs[j])) {
                    adj[i].push_back(j); // i->j
                    indegree[j]++;
                }
                if(bomb(bombs[j], bombs[i])) {
                    adj[j].push_back(i); // j->i
                    indegree[i]++;
                }
            }
        }

        // built adjacency list now with possible detonations
        int maxDetonated = 0;
        for(int i = 0; i < n; ++i) {
            vector<bool> vis(n, false);
            maxDetonated = max(maxDetonated, bfs(adj, vis, i));
        }

        return maxDetonated;
    }

    int bfs(vector<vector<int>>& adj, vector<bool>& vis, int start) {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        int count = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int neighbor : adj[node]) {
                if(!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push(neighbor);
                    count++;
                }
            }
        }

        return count;
    }
};