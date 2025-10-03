class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        int n = s.length();

        int noOfChar = 2 * numRows - 2;
        string ans = "";
        
        for(int row = 0; row < numRows; row++){
            int index = row;

            while(index < n){
                ans += s[index];

                if(row != 0 and row != numRows-1){
                    int second = index + noOfChar - 2 * row;
                    if(second < n){
                        ans += s[second];
                    }
                }
                index += noOfChar;
            }
        }

        return ans;
    }
};