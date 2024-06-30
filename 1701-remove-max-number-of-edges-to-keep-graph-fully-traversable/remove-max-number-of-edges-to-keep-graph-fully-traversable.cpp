class UnionFind {
    vector<int> par;
    int distComp;

    public:
    UnionFind(int n) {
        distComp = n;
        // par.resize(n+1);
        for(int i=0; i<=n; i++) { // 1 based indexing
            par.push_back(i);
        }
    }

    int findPar(int x) {
        if(par[x] != x) {
            par[x] = findPar(par[x]);
        }

        return par[x]; // returns exact root
    }

    bool merge(int x, int y) {
        if(findPar(x) == findPar(y)) {
            return false;
        }

        par[findPar(x)] = y;
        distComp--;
        return true;
    }

    bool singleComponent() {
        return distComp == 1;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // priortise the 3 marked edges first
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {return a[0] > b[0];});


        UnionFind alice(n), bob(n);

        // max number of edges to remove = Sum (UF Alice and Bob) total edges - minimum edges that make whole graph connected for each union find
        // if either graph fails to do that, we return -1

        int edgesAdded = 0;
        for(auto &e: edges) {
            int typ = e[0];
            int from = e[1];
            int to = e[2];
            switch(typ) {
                case 3:
                    // you want to add this edge if it connects
                    // either of the graphs
                    edgesAdded += alice.merge(from, to) | bob.merge(from, to);
                    break;
                case 2:
                    edgesAdded += bob.merge(from, to);
                    break;
                case 1:
                    edgesAdded += alice.merge(from, to);
                    break;
            }
        }

                    return (alice.singleComponent() and bob.singleComponent()) ? edges.size() - edgesAdded : -1;
    }
};