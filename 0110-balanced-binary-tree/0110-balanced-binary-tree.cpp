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
    pair <int , bool> solve(TreeNode* root) {
        if(!root) return {0 , true};
        if(!root->left && !root->right) return {1 , true};
        
        pair <int , bool> left = solve(root->left);
        pair <int , bool> right = solve(root->right);
        
        pair <int , int> cur;
        
        cur.first = max(left.first , right.first) + 1;
        cur.second = left.second && right.second && abs(left.first - right.first) <= 1;
        
        return cur;
    }
    
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};