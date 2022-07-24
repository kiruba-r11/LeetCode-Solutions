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
    void solve(TreeNode* root , int target , long long cur , int &ans) {
        if(!root) return;
        
        if((cur + root->val) == target) ans++;
        
        solve(root->left , target , (cur + root->val) , ans);
        solve(root->right , target , (cur + root->val) , ans);
    }
    
    void helper(TreeNode* root , int target , long long cur , int &ans) {
        if(!root) return;
        
        solve(root , target , 0 , ans);
        helper(root->left , target , 0 , ans);
        helper(root->right , target , 0 , ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        helper(root , targetSum , 0 , ans);
        return ans;
    }
};