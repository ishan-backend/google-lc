class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        if(n == 0) return 0;

        int res = target[0];
        for(int i=1; i<target.size(); i++) {
            if(target[i] > target[i-1])
            res += (target[i] - target[i-1]);
        }

        return res;
    }
};