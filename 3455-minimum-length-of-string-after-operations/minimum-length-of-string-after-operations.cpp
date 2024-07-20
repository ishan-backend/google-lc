class Solution {
public:

    int minimumLength(string s) {
        // observation:
        // a number takes out 2 extra
        // b -> 4 -> leftover: 2
        // b -> 5 -> leftover: 1
        // b -> 2 -> leftover: 2
        // b -> 1 -> leftover: 1

        map<char, int> mp;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
        }

        int count=0;
        for(auto it: mp) {
            if(it.second % 2 == 0) count += 2;
            else count += 1;
        }

        return count;
    }
};