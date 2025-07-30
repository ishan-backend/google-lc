class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        /*
        a & b = min(a, b)
        so for nums array, it is. <= smallest element of nums

        maxm bitwise & for a subarray = max val element of nums subarray only having max val
        */

        if(nums.empty())
            return 0;
        
        int maxv = 0;
        for(auto n: nums){ 
            if(n > maxv)
                maxv = n;
        }

        int maxl = 0, curl = 0;
        for(auto n: nums) {
            if(n == maxv) {
                curl++;
            } else {
                maxl = max(maxl, curl);
                curl = 0;
            }
        }

        return max(maxl, curl);
    }
};