class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // path compression
        }
        return parent[u];
    }

    // returns true if union is successful (i.e., they were in different sets)
    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        parent[pu] = pv;
        return true;
    }

    // Count number of unique parents = number of components
    int countComponents(int n) {
        unordered_set<int> comps;
        for (int i = 1; i <= n; i++) {
            comps.insert(find(i));
        }
        return comps.size();
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuA(n), dsuB(n);
        int usedEdges = 0;

        // Type 3 (shared) edges first
        for (auto& edge : edges) {
            if (edge[0] == 3) {
                int u = edge[1], v = edge[2];
                bool a = dsuA.unite(u, v);
                bool b = dsuB.unite(u, v);
                if (a | b) usedEdges++; // edge connects at least one graph
            }
        }

        // Type 1 (Alice only)
        for (auto& edge : edges) {
            if (edge[0] == 1) {
                int u = edge[1], v = edge[2];
                if (dsuA.unite(u, v)) usedEdges++;
            }
        }

        // Type 2 (Bob only)
        for (auto& edge : edges) {
            if (edge[0] == 2) {
                int u = edge[1], v = edge[2];
                if (dsuB.unite(u, v)) usedEdges++;
            }
        }

        // Final check: both graphs must be fully connected (1 component)
        if (dsuA.countComponents(n) > 1 || dsuB.countComponents(n) > 1)
            return -1;

        return edges.size() - usedEdges;
    }
};