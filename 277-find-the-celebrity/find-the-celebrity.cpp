/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // indegree and outdegree solution requires n^2 calls to API
        // we want something that requires < 3*n calls

        // find possible candidate
        // The first loop is to find the candidate as the author explains. In detail, suppose the candidate after the first for loop is person k, it means 0 to k-1 cannot be the celebrity, because they know a previous or current candidate. Also, since k knows no one between k+1 and n-1, k+1 to n-1 can not be the celebrity either. Therefore, k is the only possible celebrity, if there exists one.
        int cand = 0;
        for(int i=1; i<n; i++) {
            if(knows(cand, i)) { // if cand knows i, i can be celebrity
                cand = i; // 0 to i-1 cannot be celebrity, because they know either previous or current candidate
            }
        }

        // The remaining job is to check if k indeed does not know any other persons and all other persons know k
        for(int i=0; i<n; i++) {
            if(i != cand && (knows(cand, i) || !knows(i, cand)))
            // if candidate selected knows someone else or if someone doesnt know candidate
            return -1;
        }

        return cand;
    }
};