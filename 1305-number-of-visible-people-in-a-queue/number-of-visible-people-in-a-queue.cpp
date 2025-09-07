class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> stk; // Each index in the stack represents a person who is still “looking to the right” and hasn’t been completely blocked yet.
        vector<int> ans(n, 0); 

        for(int i=0; i<n; i++) {
            // stk 10, 6, 8, 5 when 11 arrives all are popped
            while(!stk.empty() and heights[i] > stk.top().first) {
                auto el = stk.top();
                stk.pop();
                int elIndx = el.second;
                ans[elIndx]++;
            }

            if(!stk.empty()) {
                ans[stk.top().second]++;
            }

            stk.push({heights[i], i});
        }

        // while(!stk.empty()) {
        //         auto el = stk.top();
        //         stk.pop();
        //         int elIndx = el.second;
        //         ans[elIndx] = n-1-elIndx;
        // }

        return ans;
    }
};