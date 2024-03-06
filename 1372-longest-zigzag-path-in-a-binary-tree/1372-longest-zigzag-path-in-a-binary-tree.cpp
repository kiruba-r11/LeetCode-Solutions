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
    pair <int , int> solve(TreeNode* root) {
    
        if(!root) return {0 , 0};
        if(!root->left && !root->right) return {1 , 1};
        
        pair <int , int> left = solve(root->left);
        pair <int , int> right = solve(root->right);
        
        pair <int , int> cur = {left.second + 1 , right.first + 1};
        
        ans = max(ans , cur.first);
        ans = max(ans , cur.second);
        ans = max(ans , left.first);
        ans = max(ans , right.second);
        
        return cur;
    }
    
    int longestZigZag(TreeNode* root) {
        solve(root);
        return ans == 0 ? 0 : ans - 1;
    }
};