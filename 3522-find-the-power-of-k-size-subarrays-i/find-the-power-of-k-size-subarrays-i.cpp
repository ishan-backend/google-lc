class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        // 0 to k-1
        int curr = 1;
        for(int i=1; i<k; i++) {
            if(nums[i] == nums[i-1]+1)
                curr++;
            else
                curr = 1; // otherwise last element of first subarray k only is valid, to handle case where prev: -1, and curr element > last element
        }

        vector<int> ans(nums.size()-k+1, -1);
        if(curr == k) {
            ans[0] = nums[k-1];
        }

        for(int l=1, r=k; r<n; l++, r++) {
            if(nums[r] == nums[r-1]+1)
                curr++;
            else
                curr = 1;
            if(curr >= k)
                ans[l] = nums[r];
        }

        return ans;
    }
};