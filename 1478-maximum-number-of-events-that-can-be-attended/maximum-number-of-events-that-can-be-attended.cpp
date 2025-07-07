class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        sort(events.begin(), events.end());
        
        int maxmday = 0;
        for(auto it: events)
        {
            maxmday = max(maxmday, it[1]);
        }
        
        int ans = 0;
        int i=0;

        // For each day we'll keep assigning 1 event if possible.
        for(int day = 1; day <= maxmday; day++)
        {
            
            
            // Pop all events which cant be attended now
            while(pq.size() and pq.top() < day)
            {
                pq.pop();
            }
            
            
            // All days with same start as day, and diff ends push into pq.
            while(i < events.size() and events[i][0] == day)
            {
                pq.push(events[i][1]);
                i++;
            }
            
            // pop one event, if avail, for attending on current day
            if(pq.size())
            {
                pq.pop();
                ans++; //one event added.
            }
            
        }
        
        return ans;
    }
};