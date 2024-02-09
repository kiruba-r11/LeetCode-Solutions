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
    void path(TreeNode* root , int target , long long sum) {
        if(!root) return ;
        if(root->val + sum == target) ans++;

        path(root->left , target , sum + root->val);
        path(root->right , target , sum + root->val);
    }
    void helper(TreeNode* root , int target) {
        if(!root) return;
        path(root , target , 0);
        helper(root->left , target);
        helper(root->right , target);
    }
    int pathSum(TreeNode* root, int targetSum) {
        helper(root , targetSum);
        return ans;
    }
};