class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
    int nearestExit(vector<vector<char>>& m, vector<int>& e) {
        queue<pair<int, int>> q;
        q.push({e[0], e[1]});
        int ans = 1;

        int r = m.size();
        int c = m[0].size();
        m[e[0]][e[1]] = '+'; // mark as visited or obstacle
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                auto fr = q.front();
                q.pop();

                for(int d=0; d<4; d++) {
                    int nr = fr.first + dirs[d][0];
                    int nc = fr.second + dirs[d][1];
                    if(nr < 0 or nc < 0 or nr >= r or nc >= c or m[nr][nc] == '+')
                        continue;
                    
                    // exit
                    if(nr == 0 or nc == 0 or nr == r-1 or nc == c-1) 
                        return ans;
                    
                    m[nr][nc] = '+';
                    q.push({nr, nc});
                }
            }
            ans++;
        }

        return -1;
    }
};