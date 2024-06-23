class Solution {
public:

    string toposort(unordered_map<char, unordered_set<char>> &adj) {
        unordered_map<char, int> indeg;
        queue<char> q;

        for(auto x: adj) {
            for(auto ch: x.second) {
                ++indeg[ch];
            }
        }

        // there can be nodes in graph with indeg 0 which are not yet present in indeg map
        for(auto x: adj) {
            // add 0 indeg nodes in queue
            if(!indeg[x.first])
                q.push(x.first);
        }

        // BFS
        string ans = "";
        while(!q.empty()) {
            char ch = q.front();
            q.pop();
            ans += ch;

            for(auto n: adj[ch]) {
                --indeg[n];
                if(indeg[n] == 0) {
                    q.push(n);
                }
            }
        }
        cout<<ans<<endl;
        return ans.size() != adj.size() ? "" : ans;
    }


    string alienOrder(vector<string>& words) {
        // t->f, w->e, r->t, e->r
        unordered_map<char, unordered_set<char>> adj;
        for(auto w: words) {
            for(auto ch: w) {
                if(!adj.count(ch)) {
                    adj[ch] = unordered_set<char>();
                }
            }
        }

        for(int i=0; i+1<words.size(); i++) {
            // between two adjacent words, find minimum length and find first different char and add an edge
            string fw = words[i];
            string sw = words[i+1];
            int minLen = min(fw.size(), sw.size());

            // edge case: abc, ab --> c->null (claim incorrect)
            if(fw.size() > sw.size() and fw.compare(0, sw.size(), sw) == 0)
                return "";

            for(int j=0; j<minLen; j++) {
                char fc = fw[j];
                char sc = sw[j];
                if(fc != sc) {
                    // fc -> sc
                    adj[fc].insert(sc);
                    break;
                }
            }
        }

        return toposort(adj);
    }
};