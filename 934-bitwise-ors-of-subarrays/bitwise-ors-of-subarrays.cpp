class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // count of distinct ORs of the subarrays of arr
        unordered_set<int> ans;   // To store all unique OR results.
        unordered_set<int> prev;  // OR results from previous step.
        prev.insert(0);           // Start with OR = 0

        for(auto x : arr) {
            unordered_set<int> curr;
            for(int y : prev) {
                curr.insert(x | y);   // Extend all previous ORs with x
            }
            curr.insert(x);           // Also include subarray of just x
            prev = curr;              // Save current ORs for next iteration
            ans.insert(curr.begin(), curr.end()); // Add all to global result
        }

        return ans.size(); // Number of unique OR results from all subarrays
    }
};