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
    int solve(TreeNode* root , int &ans) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int lh = solve(root->left , ans);
        int rh = solve(root->right , ans);
        
        ans = max(ans , lh + rh + 1);
        
        return max(lh , rh) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root , ans);
        return ans != 0 ? ans - 1 : ans;
    }
};