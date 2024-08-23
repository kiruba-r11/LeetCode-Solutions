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
    // {max_val , min_val , is_bst , sum}
    vector <int> solve(TreeNode* root) {
        if(!root) return {(int)-1e5 , (int)1e5 , 1 , 0};
        if(!root->left && !root->right) {
            ans = max(ans , root->val);
            return {root->val , root->val , 1 , root->val};
        }
        
        vector <int> left = solve(root->left);
        vector <int> right = solve(root->right);
        
        vector <int> cur(4);
        
        // check max
        cur[0] = max(max(left[0] , right[0]) , root->val);
        
        // check min
        cur[1] = min(min(left[1] , right[1]) , root->val);
        
        // check is_bst
        if(left[2] == 1 && right[2] == 1 && root->val > left[0] && root->val < right[1]) cur[2] = 1;
        
        // check sum
        cur[3] = left[3] + right[3] + root->val;
        
        if(cur[2] == 1) ans = max(ans , cur[3]);
        
        return cur;
    }
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};