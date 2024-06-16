class SegmentTree {
    private:
        const static int N = 1e5+2;
    public:
        int arr[N];
        typedef pair<int,pair<int,int>> tri;
        // storing triplet (peakCount, (rangeStart, rangeEnd))
        tri tree[4*N];
        void build(int node, int start, int end) {
            if(start == end) {
                tree[node] = {0, {start, end}};
                return;
            }

            int mid = (start+end)/2;
            build(2*node, start, mid);
            build(2*node+1, mid+1, end);
            
            // merge operation
            int ans = tree[2*node].first + tree[2*node+1].first;
            int size1 = tree[2*node].second.second-tree[2*node].second.first+1;                 // size of subarray1
            int size2 = tree[2*node+1].second.second-tree[2*node+1].second.first+1;             // size of subarray2
            int idx1 = tree[2*node].second.second;                                              // end element of subarray1
            int idx2 = tree[2*node+1].second.first;                                             // start element of subarray2

            // checking if end element of subarray1 is a peak element ?
            if(size1 > 1 && arr[idx1] > arr[idx1+1] && arr[idx1] > arr[idx1-1]) {
                ans++;
            }
            // checking if start element of subarray2 is a peak element ?
            if(size2 > 1 && arr[idx2] > arr[idx2+1] && arr[idx2] > arr[idx2-1]) {
                ans++;
            }

            // merge result
            tree[node] = {ans, {tree[2*node].second.first, tree[2*node+1].second.second}};
        }
        tri query(int node, int start, int end, int l, int r) {
            // not in the range
            if(start > r || end < l) {
                return {0, {-1, -1}};
            }

            if(l <= start && end <= r) {
                return tree[node];
            }

            int mid = (start + end)/2;
            tri q1 = query(2*node, start, mid, l, r);
            tri q2 = query(2*node+1, mid+1, end, l, r);

            // both q1 & q2 doesn't contain the ans, so we return {0,{-1,-1}}, to make sure it doesn't merge with this in future
            if(q1.second.first == -1 && q2.second.first == -1) {
                return {0, {-1, -1}};
            }
            // only q2 contains the ans, so return q2
            if(q1.second.first == -1) {
                return q2;
            }
            // only q1 contains the ans, so return q1
            if(q2.second.first == -1) {
                return q1;
            }

            // merge operation
            int ans = q1.first + q2.first;
            int size1 = q1.second.second-q1.second.first+1;                 // size of subarray1
            int size2 = q2.second.second-q2.second.first+1;                 // size of subarray2
            int idx1 = q1.second.second;                                    // end element of subarray1
            int idx2 = q2.second.first;                                     // start element of subarray2

            // checking if end element of subarray1 is a peak element ?
            if(size1 > 1 && arr[idx1] > arr[idx1+1] && arr[idx1] > arr[idx1-1]) {
                ans++;
            }
            // checking if start element of subarray2 is a peak element ?
            if(size2 > 1 && arr[idx2] > arr[idx2+1] && arr[idx2] > arr[idx2-1]) {
                ans++;
            }

            // return merge result
            return {ans, {q1.second.first, q2.second.second}};
        }
        void update(int node, int start, int end, int idx, int val) {
            if(start == end) {
                arr[idx] = val;
                tree[node] = {0, {start, end}};
                return;
            }

            int mid = (start+end)/2;
            if(idx <= mid) {
                update(2*node, start, mid, idx, val);
            } else {
                update(2*node+1, mid+1, end, idx, val);
            }
            
            // merge operation
            int ans = tree[2*node].first + tree[2*node+1].first;
            int size1 = tree[2*node].second.second-tree[2*node].second.first+1;                 // size of subarray1
            int size2 = tree[2*node+1].second.second-tree[2*node+1].second.first+1;             // size of subarray2
            int idx1 = tree[2*node].second.second;                                              // end element of subarray1
            int idx2 = tree[2*node+1].second.first;                                             // start element of subarray2

            // checking if end element of subarray1 is a peak element ?
            if(size1 > 1 && arr[idx1] > arr[idx1+1] && arr[idx1] > arr[idx1-1]) {
                ans++;
            }
            // checking if start element of subarray2 is a peak element ?
            if(size2 > 1 && arr[idx2] > arr[idx2+1] && arr[idx2] > arr[idx2-1]) {
                ans++;
            }

            // merge result
            tree[node] = {ans, {tree[2*node].second.first, tree[2*node+1].second.second}};
        }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree segTree;
        for(int i=0;i<nums.size();i++) {
            segTree.arr[i] = nums[i];
        }
        segTree.build(1, 0, nums.size()-1);
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++) {
            if(queries[i][0] == 1) {
                int l = queries[i][1];
                int r = queries[i][2];
                ans.push_back(segTree.query(1, 0, nums.size()-1, l, r).first);
            } else {
                int idx = queries[i][1];
                int val = queries[i][2];
                segTree.update(1, 0, nums.size()-1, idx, val);
            }
        }
        return ans;
    }
};