class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        // RTL
        for(int i=heights.size()-1; i>=0; i--) {
            if(ans.empty() or heights[i] > heights[ans.back()])
                ans.push_back(i);
        }

        return vector<int>(rbegin(ans), rend(ans));
    }
};