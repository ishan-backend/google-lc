class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree (numCourses, 0);

        unordered_map<int, vector<int>> adj ;
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(auto it: adj) {
            for(int node: adj[it.first]) {
                inDegree[node]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for(int ngbr: adj[node]) {
                inDegree[ngbr]--;
                if(inDegree[ngbr] == 0) {
                    q.push(ngbr);
                }
            }
        }

        reverse(ans.begin(), ans.end());
        if(ans.size() == numCourses) return ans;
        ans.clear();

        return ans;
    }
};