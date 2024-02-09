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
    TreeNode* solve(TreeNode* root , int limit , int ans) {
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL) {
            if(root->val + ans >= limit) return root;
            return NULL;
        }
        root->left = solve(root->left , limit , ans + root->val);
        root->right = solve(root->right , limit , ans + root->val);
        if(root->left == NULL && root->right == NULL) return NULL;
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int ans = 0;
        return solve(root , limit , ans);
    }
};