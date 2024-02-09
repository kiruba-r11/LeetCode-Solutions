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
    pair <int , int> univalue(TreeNode* root) {
        if(!root) return {-1 , 0};
        if(!root->left && !root->right) return {root->val , 1};
        
        pair <int , int> left = univalue(root->left);
        pair <int , int> right = univalue(root->right);
        
        if(root->val == left.first && root->val == right.first) {
            ans = max(ans , left.second + right.second + 1);
            return {root->val , max(left.second , right.second) + 1};
        } else if(root->val == left.first) {
            ans = max(ans , right.second);
            return {root->val , left.second + 1};
        } else if(root->val == right.first) {
            ans = max(ans , left.second);
            return {root->val , right.second + 1};
        } 
        
        ans = max(ans , max(left.second , right.second));
        return {root->val , 1};
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        ans = max(ans , univalue(root).second);
        return ans - 1;
    }
};