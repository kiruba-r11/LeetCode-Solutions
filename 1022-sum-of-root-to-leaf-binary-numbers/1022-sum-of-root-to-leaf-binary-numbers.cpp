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
            cur = cur * 2 + root->val;
            ans += cur;
            return ;
        }
        
        solve(root->left , ans , cur * 2 + root->val);
        solve(root->right , ans , cur * 2 + root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0 , cur = 0;
        solve(root , ans , cur);
        return ans;
    }
};