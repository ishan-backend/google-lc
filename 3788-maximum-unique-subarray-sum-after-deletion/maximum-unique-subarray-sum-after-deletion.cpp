class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = 0;
        map<int, bool> mp;
        for(auto n: nums) {
            ans += (n > 0 && mp[n] == false ? n : 0);
            mp[n] = true;
        }

        if(ans == 0) {
            sort(nums.begin(), nums.end());
            return nums.back();
        }
        return ans;
    }
};