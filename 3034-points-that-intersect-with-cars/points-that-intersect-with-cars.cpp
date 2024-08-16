class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> mp(102, 0);
        for(auto n: nums) {
            mp[n[0]]++;
            mp[n[1]+1]--;
        }

        int ans = 0;
        int sum = 0;
        for(int i=1; i<101; i++) {
            sum += mp[i];
            if(sum > 0)
                ans++;
        }

        return ans;
    }
};