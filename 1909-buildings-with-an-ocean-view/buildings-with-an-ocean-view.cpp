class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        // vector<int> ans;
        // RTL
        // for(int i=heights.size()-1; i>=0; i--) {
        //     if(ans.empty() or heights[i] > heights[ans.back()])
        //         ans.push_back(i);
        // }

        // return vector<int>(rbegin(ans), rend(ans));

        // LTR
        // monotonically decreasing stack
        // we will push element to stack if we have same height as top(we will remove all such)
        // when new height comes in from right, we will compare against stack and enter it
        // monotonically decreasing stack will be my ans, and it will store indexes
        vector<int> stk;
        for(int i=0; i<heights.size(); i++) {
            while(!stk.empty() and heights[i] >= heights[stk.back()]) {
                stk.pop_back();
            }
            stk.push_back(i);
        }

        return stk;
    }
};