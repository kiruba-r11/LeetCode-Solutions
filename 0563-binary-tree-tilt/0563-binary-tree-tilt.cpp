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
    int solve(TreeNode* root , int &tilt) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        int left = solve(root->left , tilt);
        int right = solve(root->right , tilt);
        
        tilt += abs(left - right);
        return root->val + left + right;
    }
    int findTilt(TreeNode* root) {
        int tilt = 0;
        solve(root , tilt);
        return tilt;
    }
};