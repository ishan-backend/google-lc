class MajorityChecker {
public:
    // https://leetcode.com/problems/online-majority-element-in-subarray/solutions/356108/random-pick/

    vector<int> carr;
    unordered_map<int, vector<int>> ump;
    MajorityChecker(vector<int>& arr) {
        carr = arr;
        for(int i=0; i<arr.size(); i++) {
            ump[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for(int times = 0; times < 20; times++) {
            auto it = ump.find(carr[left + rand()%(right-left+1)]);
            const auto &idsarr = it->second;

            if((upper_bound(begin(idsarr), end(idsarr), right) - lower_bound(begin(idsarr), end(idsarr), left)) >= threshold) {
                return it->first;
            }
        }

        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */