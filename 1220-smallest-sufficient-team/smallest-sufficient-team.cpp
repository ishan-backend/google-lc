class Solution {
public:
    unordered_map<int, vector<int>> memo;
    vector<int> pmsk;  // people skill masks
    int m;

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string, int> sidx;

        for (int i = 0; i < n; i++) {
            sidx[req_skills[i]] = i;
        }

        m = people.size();
        pmsk = vector<int>(m, 0);

        for (int i = 0; i < m; i++) {
            for (const auto& skill : people[i]) {
                if (sidx.count(skill)) {
                    pmsk[i] |= (1 << sidx[skill]);
                }
            }
        }

        int allSkills = (1 << n) - 1;
        return solve(allSkills); // dp(mask) returns the smallest team to cover mask skills.
    }

    vector<int> solve(int mask) {
        if (mask == 0) return {};
        if (memo.count(mask)) return memo[mask];

        vector<int> res;
        for (int i = 0; i < m; ++i) {
            int newMask = mask & ~pmsk[i]; // This line is used to remove the skills that person i can provide from the current mask (which represents the set of remaining skills needed).
            if (newMask == mask) continue;  // this person adds no new skill

            vector<int> team = solve(newMask);
            team.push_back(i);

            // team.size(): the number of people in the current candidate team
	        // res.size(): the number of people in the best team found so far
            if (res.empty() || team.size() < res.size()) {
                res = team;
            }
        }

        return memo[mask] = res;
    }
};