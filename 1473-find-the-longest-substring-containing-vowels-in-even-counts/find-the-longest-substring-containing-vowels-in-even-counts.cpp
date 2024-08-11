class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int, int> um;
        um[0] = -1; // mask to first index of occurring

        int ans = 0;
        int mask = 0; // only marks vowels
        string vow = "aeiou";

        for(int i=0; i<n; i++) {
            for(int j=0; j<5; j++) {
                if(s[i] == vow[j]) {
                    // set it in mask and break
                    mask = mask ^ (1<<j);
                    break;
                }
            }
            if(!um.count(mask)) {
                // if mask is not found yet in um
                um[mask] = i; // first index
            }

            ans = max(ans, i-um[mask]); // difference of current idex and vowels incl mask
        }

        return ans;
    }
};