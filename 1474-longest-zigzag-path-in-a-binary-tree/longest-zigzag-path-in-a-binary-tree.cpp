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
    int ans = 0;
    void dfs(TreeNode* root, bool toLeft, int curAns) {
        if(root == nullptr) {
            return;
        }

        ans = max(ans, curAns);
        if(toLeft) { // go to left child
            // 2 choices
            dfs(root->left, false, curAns+1);
            // or start to create a new zig zag path from root to root->left
            dfs(root->right, true, 1);
        } else {
            // for current zig zag path, we are intended to go to right
            // in that case for next child toLeft will be true
            dfs(root->right, true, curAns + 1);
            // else create a new zig zag path going to left from root to root->right
            dfs(root->left, false, 1);
        }

    }

    int longestZigZag(TreeNode* root) {
        dfs(root, false, 0); // when it is at root-left, it has to go to right so toLeft is false
        dfs(root, true, 0);
        return ans;
    }
};