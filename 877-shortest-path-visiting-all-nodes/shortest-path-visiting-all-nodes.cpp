class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int allvis = (1<<n)-1;

        // BFS
        queue<pair<int, pair<int, int>>> q; // curnode -> {distance, current nodes travelled shown by mask}
        set<pair<int, int>> vis; // states that have been visited once

        for(int i=0; i<n; i++) {
            q.push({i, {0, (1<<i)}});
            vis.insert({i, (1<<i)});
        }

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            int curnode = curr.first;
            int dist = curr.second.first;
            int mask = curr.second.second;

            if(mask == allvis)
                return dist; // BFS guarentees shortest path

            for(auto nextnode : graph[curnode]) {
                int nextMask = mask | (1<<nextnode);
                if(!vis.count({nextnode, nextMask})) {
                    q.push({nextnode, {dist+1, nextMask}});
                    vis.insert({nextnode, nextMask});
                }
            }
        }

        return 0;
    }
};