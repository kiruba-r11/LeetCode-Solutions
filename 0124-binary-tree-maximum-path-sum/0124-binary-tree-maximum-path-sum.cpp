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
    int ans = -1001;
    // {extendible path, non-extendible path}
    pair <int , int> solve(TreeNode* root) {
        if(!root) return {-1001 , -1001};
        if(!root->left && !root->right) {
            ans = max(ans , root->val);
            return {root->val , root->val};
        }
        
        pair <int , int> left = solve(root->left);
        pair <int , int> right = solve(root->right);
        
        pair <int , int> cur;
        
        // Extendible path for cur:
        // max(left extendible path + cur_sum , right extendible path + cur_sum , cur_sum)
        cur.first = max(max(left.first , right.first) + root->val , root->val);
        
        
        // Non-Extendible path for cur:
        // max( left non-extendible path , 
        //      right non-extendible path ,
        //      left extendible path + right extendible path + cur_sum)
        cur.second = max(max(left.second , right.second) , left.first + right.first + root->val);
        
        ans = max(ans , max(cur.first , cur.second));
        
        return cur;
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};