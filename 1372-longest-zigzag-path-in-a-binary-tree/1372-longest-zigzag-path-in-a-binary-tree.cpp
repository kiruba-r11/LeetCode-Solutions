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
    
        if(!root) return {-1 , -1};
        if(!root->left && !root->right) return {0 , 0};
        
        pair <int , int> l = solve(root->left , ans);
        pair <int , int> r = solve(root->right , ans);
        
        ans = max(ans , 1 + max(l.second , r.first));
        return {l.second + 1 , r.first + 1};
    }
    
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        solve(root , ans);
        return ans;
    }
};