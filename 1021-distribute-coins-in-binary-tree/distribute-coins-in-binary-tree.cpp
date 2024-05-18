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

    int postOrderRecursion(TreeNode* root, int &moves) { // returns + / - of the balance of coins
        if(root == nullptr) return 0;
        int lbal = postOrderRecursion(root->left, moves);
        int rbal = postOrderRecursion(root->right, moves);

        // actual logic for adding to moves from current root to its left and right child
        moves += abs(lbal) + abs(rbal); 
        // now return the balance of coins back, once we can settle all 1s
        return root->val + lbal + rbal - 1; // -1 because 1 coin will be used here
    }

    int distributeCoins(TreeNode* root) {
        int ans = 0;
        postOrderRecursion(root, ans);
        return ans;
    }
};