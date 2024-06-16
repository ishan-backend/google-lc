class Solution {
public:
    vector<long long> dp;

    long long rec(vector<pair<int, int>> &arr, int i) {
        if(i >= arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        long long not_take = rec(arr, i+1);
        int next_i = i+1;
        while(next_i < arr.size() and arr[next_i].first < arr[i].first+3) { // atleast 3 bada hona chahiye
            ++next_i;
        }

        long long take = (long long) arr[i].first * arr[i].second + rec(arr, next_i);
        return dp[i] = max(take, not_take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> fr;
        int n = power.size();
        for(int i=0; i<n; i++) {
            fr[power[i]]++;
        }

        vector<pair<int, int>> arr;
        for(auto &it: fr) {
            arr.push_back(it);
        }

        dp.assign(power.size(), -1);
        return rec(arr, 0);
    }
};


/*



*/