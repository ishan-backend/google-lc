class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using pii = pair<int, int>;
        vector<vector<pii>> g(n+1); // adj list
        for(auto &t: times) {
            g[t[0]].push_back({t[1], t[2]});
        }

        const int inf = 1e9;
        vector<int> dist(n+1, inf);
        vector<bool> vis(n+1, false);

        dist[k] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> min_pq;
        min_pq.push({0, k}); // dist, node
        while(!min_pq.empty()) {
            auto t = min_pq.top();
            min_pq.pop();

            if(vis[t.second])
                continue; // already relaxed node since that would be visited from node k
            vis[t.second] = true;
            for(auto u : g[t.second]) {
                int v = u.first; // node to
                int w = u.second; // weight

                if(dist[v] > dist[t.second] + w) {
                    dist[v] = dist[t.second] + w;
                    min_pq.push({dist[v], v});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end()); // 1 based indexing of nodes
        return ans == inf ? -1 : ans;
    }
};