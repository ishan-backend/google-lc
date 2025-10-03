class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 or numRows > s.size())
            return s;

        int c = 0, d = 1;
        vector<vector<char>> rows(numRows); // save into this
        for(char ch: s) {
            rows[c].push_back(ch);
            if(c == 0) {
                d = 1;
            } else if(c == numRows-1) {
                d = -1;
            }

            c += d; // move up or down
        }

        string res = "";
        for(auto r : rows) {
            for(char c: r) {
                res += c;
            }
        }

        return res;
    }
};