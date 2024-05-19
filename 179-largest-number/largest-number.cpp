class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num;
        for(auto it: nums) {
            num.push_back(to_string(it));
        }

        // s1 will be before s2 if 
        sort(begin(num), end(num), [](string &s1, string &s2) { return s1+s2 > s2+s1; });
        string res = "";
        for(auto s: num) {
            res += s;
        }

        while(res[0] == '0' and res.length() > 1) {
            res.erase(0, 1);
        }

        return res;
    }
};