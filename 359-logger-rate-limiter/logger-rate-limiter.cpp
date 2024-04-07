class Logger {
public:
    unordered_map<string, int> mp; // message -> TS
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message) == mp.end()) {
            mp[message] = timestamp;
            return true;
        }

        // when we dont need to rate limit
        if(timestamp-mp[message] >= 10) {
            mp[message] = timestamp;
            return true;
        } else {
            // we need to rate limit
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */