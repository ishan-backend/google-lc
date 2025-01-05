class Solution {
    struct Log {
        int id;
        bool isStart;
        int time;
    };

    Log getLog(string& s) {
        string id, isStart, time;
        istringstream ss(s);
        getline(ss, id, ':');
        getline(ss, isStart, ':');
        getline(ss, time, ':');

        return {stoi(id), isStart == "start", stoi(time)};
    }


public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        // https://leetcode.com/problems/exclusive-time-of-functions/solutions/1024327/c-o-number-of-log-lines-stack-solution-with-diagram/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months&difficulty=MEDIUM%2CHARD
        vector<int> excl(n, 0);
        stack<Log> s;

        for(auto &log: logs) {
            Log l = getLog(log);
            if(l.isStart) {
                s.push(l);
            } else {
                // calculate time with start log
                int time = l.time - s.top().time + 1;
                // add exclusive time for this id
                excl[l.id] += time;

                // remove start log for this pair
                s.pop();
                if(!s.empty()) {
                    // if stack is not empty, remove this contribution from previous pair
                    excl[s.top().id] -= time;
                }
            }
        }

        return excl;
    }
};