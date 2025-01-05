/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        // we need to start our search from our target value 
        // from there, we want to expand left & right as far as possible 
        // untill we reach a leaf node
        // whatever leaf node is reached first much be the closest
        
        // bfs makes the most sense here because we can expand left and right easily in each step
        unordered_map<int, TreeNode*> nodeMap;
        unordered_map<int, vector<int>> adjList;
        
        buildGraph(adjList, nodeMap, root);

        // if k is a leaf itself
        if(adjList[k].size() == 1 && !nodeMap[k]->left && !nodeMap[k]->right) return k;
        
        // bfs
        vector<int> visited(1001);
        deque<int>q;

        q.push_back(k);

        while(!q.empty()) {
            int node = q.front();
            q.pop_front();
            visited[node] = 1;
            for (int neigh : adjList[node]) {
                if (!visited[neigh]) {
                    q.push_back(neigh);
                }
            }
            // Check if the current node is a leaf
            if (!nodeMap[node]->left && !nodeMap[node]->right) {
                return node;
            }
        }

        return 0;
    }

    void buildGraph(unordered_map<int, vector<int>>& adjList, unordered_map<int, TreeNode*>& nodeMap, TreeNode* root) {
        // This base case isn't actually needed because we check if the left or right node exists already
        // But it's good to be explicit
        if (!root) return;
        
        // Map the value of the node to the node root
        nodeMap[root->val] = root;

        // Build our adj list (graph representation)
        if (root->left) {
            adjList[root->val].push_back(root->left->val);
            adjList[root->left->val].push_back(root->val);
            buildGraph(adjList, nodeMap, root->left);
        }
        if (root->right) {
            adjList[root->val].push_back(root->right->val);
            adjList[root->right->val].push_back(root->val);
            buildGraph(adjList, nodeMap, root->right);
        }

        return;
    }
};