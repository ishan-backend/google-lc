using psi = pair<int, string>;
//       So, as per the question we want the decreasing order for the frequency of the strings and increasing order in the lexiographical way
// bottom to top order
class myComparator {
public:
    // comparator for max heap = ascending from bottom to top
    bool operator() (const psi &p1, const psi &p2) {
        if(p1.first == p2.first) return p1.second < p2.second; // p1 will come before p2 if its lexicographically smaller
        return p1.first > p2.first; // p1 will come before p2 if its frequency is higher
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> fr;
        for(string word: words) {
            fr[word]++;
        }

        priority_queue<psi, vector<psi>, myComparator> pq;
        for(auto it: fr) {
            pq.push({it.second, it.first});

            if(pq.size() > k)
                pq.pop();
        }

        vector<string> ans(k);
        int m = k-1;
        while(pq.size()) {
            ans[m--] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};