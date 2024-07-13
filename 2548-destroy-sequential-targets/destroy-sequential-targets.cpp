class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        unordered_map<int, int> mp; // remainder -> freq on dividing every number by space
        int maxF = 0;
        int ansNum = 0;
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>=0; i--) {
            int rem = nums[i]%space;
            mp[rem]++;
            if(mp[rem] >= maxF) {
                maxF = mp[rem];
                ansNum = nums[i];
            }
        }

        return ansNum;
    }
};