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
    pair <int , int> solve(TreeNode* root) {
    
        if(!root) return {0 , 0};
        if(!root->left && !root->right) return {root->val , 0};
        
        pair <int , int> left = solve(root->left);
        pair <int , int> right = solve(root->right);
        
        // rob this house
        int rob = root->val + left.second + right.second;
            
        // don't rob this house
        int dont_rob = max(left.first , left.second) + max(right.first , right.second);
        
        return {rob , dont_rob};
    }
    
    int rob(TreeNode* root) {
        pair <int , int> ans = solve(root);
        return max(ans.first , ans.second);
    }
};