class Solution {
public:
    bool checkValidString(string s) {
        stack<int> lstk, ststk;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                lstk.push(i);
            }
            if(s[i] == '*') {
                ststk.push(i);
            }
            if(s[i] == ')') { // on ) remove from lstk on priority, then from *stk
                if(!lstk.empty()) {
                    lstk.pop();
                } else if(!ststk.empty()) {
                    ststk.pop();
                } else {
                    return false;
                }
            }
        }

        // at last ((*(** might remain we need to validate
        // every ( encountered should have * to its right
        // if only * remains its ok
        while(!lstk.empty() and !ststk.empty()) {
            if(lstk.top() > ststk.top()) {
                // **(( lstk: [2, 3]top ststk: [0, 1]top
                // *(*(
                return false;
            }
            // ((**
            // ((*
            lstk.pop();
            ststk.pop();
        }

        return lstk.empty();
    }
};