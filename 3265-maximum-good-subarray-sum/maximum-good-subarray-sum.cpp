class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = LLONG_MIN;
        vector<long long> psum{0};
        unordered_map<int, int> ump;

        for(int i=0; i<nums.size(); i++) {
            psum.push_back(psum.back() + nums[i]);
            if(auto it = ump.find(nums[i]-k); it != ump.end())
                res = max(res, psum[i+1] - psum[it->second]); // n-k
            if(auto it = ump.find(nums[i]+k); it != ump.end())
                res = max(res, psum[i+1] - psum[it->second]); // n+k

            if(auto it = ump.find(nums[i]); it == end(ump) || psum[i] - psum[it->second] <= 0)
                ump[nums[i]] = i;
            
        }

        return res == LLONG_MIN ? 0 : res;
    }
};