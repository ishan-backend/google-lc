class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        /*
        1. Brute Force (Greedy Loop)
        Track room end times in an array busy[].

        For each meeting:

        Try assigning it to a room free at start.
        If none are free, find the earliest finishing room and delay the meeting.
        Count how many times each room is used.

        2. Optimized with Heaps
        Use two heaps:

        free: min-heap of available room indices.
        busy: min-heap of (endTime, roomIndex).
        Efficiently release and assign rooms.

        Reduces time complexity from O(m × n) to O(m log n).
        */

        sort(meetings.begin(), meetings.end());
        vector<int> cntBooked(n, 0);
        priority_queue<int, vector<int>, greater<>> free;
        using pli = pair<long long, int>;
        priority_queue<pli, vector<pli>, greater<>> busy;

        for(int i=0; i<n; i++) free.push(i);

        for(auto &meet: meetings) {
            long long st = meet[0], en = meet[1];

            // check if other rooms which were busy and now their end times have finished, assign them as free
            while(!busy.empty() and busy.top().first <= st) {
                free.push(busy.top().second);
                busy.pop();
            }

            if(!free.empty()) {
                // then we can assign meet directly
                int room = free.top(); free.pop();
                busy.emplace(en, room);
                cntBooked[room]++;
            } else {
                // wait till any busy room gets free at the earliest
                auto [availTime, room] = busy.top(); busy.pop();
                busy.emplace(availTime + (en-st), room);
                cntBooked[room]++;
            }
        }

        // now we have cntBooked with frequency, return min room index
        return max_element(cntBooked.begin(), cntBooked.end()) - cntBooked.begin();
    }
};