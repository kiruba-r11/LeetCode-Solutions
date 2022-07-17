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
    pair <int , int> solve(TreeNode* root , int &ans) {
        
        if(!root) return {1e6 , -1};
        if(!root->left && !root->right) return {root->val , root->val};
        
        pair <int , int> left = solve(root->left , ans);
        pair <int , int> right = solve(root->right , ans);
        
        int minval = min(left.first , right.first);
        int maxval = max(left.second , right.second);
        
        ans = max(ans , abs(root->val - minval));
        ans = max(ans , abs(maxval - root->val));
        
        return {min(minval , root->val) , max(maxval , root->val)};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root , ans);
        return ans;
    }
};