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
    void solve(TreeNode* root , int &ans , int cur) {
    
        if(!root) return;
        if(!root->left && !root->right) {
            cur++;
            ans = min(ans , cur);
            return;
        }
        
        solve(root->left , ans , cur + 1);
        solve(root->right , ans , cur + 1);
        
    }
    
    int minDepth(TreeNode* root) {
        int ans = INT_MAX , cur = 0;
        solve(root , ans , cur);
        return ans == INT_MAX ? 0 : ans;
    }
};