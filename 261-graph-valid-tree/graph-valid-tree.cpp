// For a graph to be a tree:
//      1. Graph must be fully connected. => Use UF to find it.
//      2. Graph must not have any cycles. => If edges >= n, then there would be cycles.

class DSU {
    public:
    vector<int> parent, rank;
    int count;
    
    DSU(int n){
        count = n;
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void Union(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py){
            if(rank[px] > rank[py])
                parent[py] = px;
            else if(rank[px] < rank[py])
                parent[px] = py;
            else {
                parent[py] = px;
                rank[px]++;
            }
            count--;
        }
    }
    int getCount(){
        return count;
    }
    
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& e) {
        if(e.size() >= n)
            return false;
        DSU uf(n);
        for(auto E: e){
            uf.Union(E[0], E[1]);
        }
        if(uf.getCount() == 1)
            return true;
        else
            return false;
    }
};
