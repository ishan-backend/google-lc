class Solution {
public:
int bound;  // Range size excluding blacklist
    unordered_map<int, int> remap;  // Map blacklisted index to valid number
    unordered_set<int> black;       // Store all blacklisted numbers

    Solution(int n, vector<int>& blacklist) {
        bound = n - blacklist.size();

        // Mark all blacklisted numbers
        for (int b : blacklist) {
            black.insert(b);
        }

        int swapTarget = n - 1;

        for (int b : blacklist) {
            if (b < bound) {
                // Find next available number not in blacklist
                while (black.count(swapTarget)) {
                    --swapTarget;
                }
                remap[b] = swapTarget;  // Remap b to valid swapTarget
                --swapTarget;
            }
        }
    }

    int pick() {
        int randIdx = rand() % bound;  // Pick from [0, bound)
        // Remap if this index was blacklisted
        return remap.count(randIdx) ? remap[randIdx] : randIdx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */