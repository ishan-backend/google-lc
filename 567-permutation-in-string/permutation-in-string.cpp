class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // permutation means, same chars should be adjacent to each other and no separate char should exist between this permuation
        vector<int> cur(26), mp(26); // use vector to compare using == directly

        for(char c : s1) 
            mp[c - 'a']++; // store freq of s1

        for(int i = 0; i < s2.size(); i++) {
            cur[s2[i] - 'a']++;

            // sliding window over size of s1, remove chars frequency
            if(i >= s1.size()) 
                cur[s2[i - s1.size()] - 'a']--;

            if(mp == cur) 
                return true;
        }
        return false;
    }
};