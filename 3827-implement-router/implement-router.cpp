#include <bits/stdc++.h>
using namespace std;

class Router {
public:
    using Packet = tuple<int, int, int>; // (source, destination, timestamp)
    queue<Packet> fifo; 
    unordered_map<int, vector<int>> destToTs; // destination -> sorted timestamps
    int memLimit;
    set<Packet> st; // deduplication

    Router(int memoryLimit) {
        memLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet p = {source, destination, timestamp};
        if (st.count(p)) return false;

        if (fifo.size() >= memLimit) {
            // remove oldest packet
            auto [a, b, c] = fifo.front();
            fifo.pop();
            st.erase({a, b, c});
            
            auto &timestamps = destToTs[b];
            auto it = lower_bound(timestamps.begin(), timestamps.end(), c);
            if (it != timestamps.end()) {
                timestamps.erase(it);
            }
        }

        fifo.push(p);
        st.insert(p);

        // keep timestamps sorted
        auto &timestamps = destToTs[destination];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), timestamp);
        timestamps.insert(it, timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (fifo.empty()) return {};

        auto [a, b, c] = fifo.front();
        fifo.pop();
        st.erase({a, b, c});

        auto &timestamps = destToTs[b];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), c);
        if (it != timestamps.end()) {
            timestamps.erase(it);
        }

        return {a, b, c};
    }
    
    int getCount(int d, int s, int e) {
        auto &vec = destToTs[d];
        int l = lower_bound(vec.begin(), vec.end(), s) - vec.begin();
        int r = upper_bound(vec.begin(), vec.end(), e) - vec.begin();
        return r - l;
    }
};