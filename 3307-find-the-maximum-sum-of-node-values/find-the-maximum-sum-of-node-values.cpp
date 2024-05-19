class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // https://leetcode.com/problems/find-the-maximum-sum-of-node-values/solutions/4812534/c-greedy-solution-visualized-comprehensive-explanation/?envType=daily-question&envId=2024-05-19
        // case: we have even no of nodes which can be xored to maximise the sum
        long long s1=0, s2=0;
        int cnt = 0;
        for(auto i: nums) {
            if((i^k) > i) {
                s1 += (i^k);
                cnt++;
            } else {
                s2 += i;
            }
        }

        if(cnt%2 == 0) {
            return s1+s2;
        }

        // case: when we have odd number of nodes, whose xor with k is greater
        // you have to choose a node, whose original value is least, leave it.
        // use s1 and s2
        // try excluding an element from s1, and add s2 with original i
        // try excluding an element from s2, add s1 and xor'ed i
        long long so1 = 0, so2 = 0;
        for(auto i: nums) {
            if((i^k) > i) {
                // sum maximise
                so1 = max(so1, s1 - (i^k) + s2 + i);
            } else {
                so2 = max(so2, s2 - i + s1 + (i^k));
            }
        }

        return max(so1, so2);
    }
};