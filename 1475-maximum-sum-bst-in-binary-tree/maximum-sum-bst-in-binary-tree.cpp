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
    // {smallest num, greatest_num, current_subtree_sum} 
    vector<int> recurse(TreeNode* root, int &ans) {
        if(!root) return {INT_MAX, INT_MIN, 0};

        vector<int> lans, rans;
        lans = recurse(root->left, ans);
        rans = recurse(root->right, ans);

        // check if curr tree is not BST, then send empty arr upwards
        if(lans.empty() or rans.empty() or root->val <= lans[1] or root->val >= rans[0]) return {};

        // if BST, update ans
        ans = max(ans, lans[2] + rans[2] + root->val);
        return {min(lans[0], root->val), max(rans[1], root->val), lans[2] + rans[2] + root->val};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        recurse(root, ans);
        return ans;
    }
};