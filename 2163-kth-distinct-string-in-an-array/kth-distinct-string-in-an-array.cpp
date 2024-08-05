class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> order;
        map<string, int> mp;

        for(auto it: arr) {
            mp[it]++;
            order.push_back(it);
        }

        int cur = 0;
        for(auto it: order) {
            if(mp[it] == 1) {
                cur++;
                if(cur == k)
                    return it;
            }
        }

        return "";
    }
};