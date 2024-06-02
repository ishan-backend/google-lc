class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first)
            return a.second < b.second; // same ascii value case me b pass wala hence < is towards it
        return a.first > b.first; // * ke pass se high ascii value hat skta h isliye 
        }
    };

    string clearStars(string s) {
        int n = s.size();
        string ans = "";

        // traverse from L to R
        // keep a min-heap
        // add pair <char-ascii, index> - cmp to keep index latest on top of heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // min heap

        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(s[i] == '*') {
                vis[pq.top().second]=1;
                vis[i]=1;
                cout << pq.top().second << endl;
                pq.pop();
            } else {
                pq.push({s[i], i});
            }
        }

        for(int i=0; i<n; i++) {
            if(vis[i] == 0)
                ans.push_back(s[i]);
        }

        return ans;
    }
};