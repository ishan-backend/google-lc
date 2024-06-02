class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp; // ordered map
        for(auto &it: intervals) {
            mp[it[0]]++, mp[it[1]]--;
        }

        int cur = 0, res = 0;
        for(auto &it: mp) {
            res = max(res, cur += it.second);
        }

        return res;
    }
};