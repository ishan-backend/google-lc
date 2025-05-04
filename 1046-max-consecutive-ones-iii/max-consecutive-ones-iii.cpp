class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0;
        int ans = 0;
        while(r < nums.size()) {
            if(nums[r] == 0)
                k--;
            r++; // imagine how r would increase to right, while l will stay behind to keep track of 0s

            if(k < 0) {
                //  If k becomes negative, it means the current window has more than k zeros, so we need to move i to the right (contract the window) and possibly increment k back if we remove a zero.
                if(nums[l] == 0)
                    k++;
                l++;
            }
        }

        return r-l;
    }
};