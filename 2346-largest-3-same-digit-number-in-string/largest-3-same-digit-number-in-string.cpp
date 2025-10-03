class Solution {
public:
    string largestGoodInteger(string num) {
        int maxn = -1;
        for(int i=0; i+2 < num.size(); i++) {
            if(num[i] == num[i+1] && num[i+1] == num[i+2]) {
                maxn = max(maxn, num[i]-'0');
            }
        }

        return (maxn == -1) ? "" : std::string(3, '0'+maxn);
    }
};