/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        // use a vector to store sum at each level in this Tree
        vector<int> levelsum;

        // bfs
        queue<NestedInteger> q;
        for(auto &ni: nestedList) {
            q.push(ni);
        }
        while(!q.empty()) {
            levelsum.push_back(0);

            // bfs level by level  
            int sz = q.size();
            while(sz--) {
                auto ni = q.front();
                q.pop();

                // if its integer, add it to current level sum
                if(ni.isInteger()) levelsum.back() += ni.getInteger();
                else {
                    // add it to queue for next BFS level processing
                    for(auto &ni2 : ni.getList()) {
                        q.push(ni2);
                    }
                }
            }
        }

        // math the answer
        // Logic: sum[num * (maxDepth - depth + 1)] --> (maxDepth - depth + 1) * sum[all nums in that level]
        int ans = 0;
        for(int i=0; i<levelsum.size(); i++) {
            ans += (levelsum[i] * (levelsum.size()-(i+1)+1));
        }

        return ans;
    }
};