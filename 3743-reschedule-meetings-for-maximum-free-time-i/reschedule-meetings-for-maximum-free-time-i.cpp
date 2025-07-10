class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        /*
            we can move k meetings -> max k+1 gaps we can merge to form one maxm possible free time
            collate all gaps
            sliding window of size k+1, update the maximum sum
        */

        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for(int i=1; i<startTime.size(); i++) {
            gaps.push_back(startTime[i]-endTime[i-1]);
        }
        gaps.push_back(eventTime-endTime.back());

        // sliding window
        int ans = 0;
        int cursum = 0;
        for(int i=0; i<gaps.size(); i++) {
            cursum += gaps[i];
            if(i >= k+1) {
                cursum -= gaps[i-(k+1)];
            }


            ans = max(ans, cursum);
        }
        return ans;
    }
};