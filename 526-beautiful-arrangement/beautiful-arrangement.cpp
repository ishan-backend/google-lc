class Solution {
public:
    int countArrangement(int n) {
        vector<bool> usednum(n+1, false);
        return rec(n, 1, usednum);
    }

    int rec(int n, int pos, vector<bool> usednum) {
        if(pos > n)
            return 1;
        
        int ans = 0;
        // try placing each unused number at current position
        for(int i=0; i<n; i++) {
            if(!usednum[i] && isBeautiful(pos, i+1)) {
                usednum[i] = true;
                // this position got beautiful, check further if permutation is beautiful
                ans += rec(n, pos+1, usednum);
                usednum[i] = false;
            }
        }

        return ans;
    }

    bool isBeautiful(int pos, int num) {
        if(pos % num == 0 || num % pos == 0)
            return true;
        
        return false;
    }
};