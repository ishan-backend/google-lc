class Solution {
public:
    vector<long> debt;
    // n! because T(n) = n*T(n-1)
    int minTransfers(vector<vector<int>>& transactions) {
        // https://leetcode.com/problems/optimal-account-balancing/solutions/95355/concise-9ms-dfs-solution-detailed-explanation/
        unordered_map<int, int> bal; // each person's overall balance
        for(auto &t: transactions) {
            bal[t[0]] -= t[2]; // given -
            bal[t[1]] += t[2]; // taken +
        }

        // only deal with non-zero debts
        for(auto &p: bal) {
            if(p.second) { // non-zero i.e. given or taken
                debt.push_back(p.second);
            }
        }

        return dfs(0);
    }

    int dfs(int idx) { // returns minm no of txns to settle debts starting from debt[idx]
        while(idx < debt.size() and !debt[idx]) idx++; // get index of next non-zero index
        int res = INT_MAX;
        for(long i=idx+1, prev=0; i<debt.size(); i++) {
            if(debt[i] * debt[idx] < 0 and debt[i] != prev) { // opp sign
                // do change
                debt[i] += debt[idx];
                
                res = min(res, 1 + dfs(idx+1));

                // undo change
                prev = (debt[i] -= debt[idx]);
            }
        }

        return res < INT_MAX ? res : 0;
    }
};