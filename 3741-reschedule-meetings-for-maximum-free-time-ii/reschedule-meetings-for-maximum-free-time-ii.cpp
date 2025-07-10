class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        /*
        Iterate over all meetings from left to right and right to left.
        For each meeting, calculate:
        left: free time before it.
        right: free time after it.
        Check if the current meeting's duration can fit into the best gap seen so far (leftMax or rightMax):
        If yes, we can move this meeting to that slot and merge three parts: left+right+duration.
        If no, just take left+right as potential free time.
        Update res with the best seen so far.
        This dual pass (left-to-right and right-to-left) ensures all shift possibilities are considered.  
        */
        int n = startTime.size();
        int maxTime = 0;
        int leftMax = 0;

        // Pass 1: left to right
        for (int i = 0; i < n; ++i) {
            int left = (i == 0) ? startTime[i] : startTime[i] - endTime[i - 1];
            int right = (i == n - 1) ? eventTime - endTime[i] : startTime[i + 1] - endTime[i];
            int duration = endTime[i] - startTime[i];

            if (leftMax >= duration) {
                maxTime = max(maxTime, left + right + duration);
            } else {
                maxTime = max(maxTime, left + right);
            }

            leftMax = max(leftMax, left);
        }

        int rightMax = 0;

        // Pass 2: right to left
        for (int i = n - 1; i >= 0; --i) {
            int left = (i == 0) ? startTime[i] : startTime[i] - endTime[i - 1];
            int right = (i == n - 1) ? eventTime - endTime[i] : startTime[i + 1] - endTime[i];
            int duration = endTime[i] - startTime[i];

            if (rightMax >= duration) {
                maxTime = max(maxTime, left + right + duration);
            } else {
                maxTime = max(maxTime, left + right);
            }

            rightMax = max(rightMax, right);
        }

        return maxTime;
    }
};