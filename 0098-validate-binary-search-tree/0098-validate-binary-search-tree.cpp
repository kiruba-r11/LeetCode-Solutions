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
    // {min , max , is_bst}
    vector <long long> is_valid(TreeNode* root) {
        if(!root) return {LLONG_MAX , LLONG_MIN , 1};
        if(!root->left && !root->right) return {root->val , root->val , 1};
        
        vector <long long> left = is_valid(root->left);
        vector <long long> right = is_valid(root->right);
        
        vector <long long> cur(3);
        if(root->val > left[1] && root->val < right[0] && left[2] && right[2]) {
            cur[2] = 1;
        }
        
        cur[0] = min(min(left[0] , right[0]) , (long long)root->val);
        cur[1] = max(max(left[1] , right[1]) , (long long)root->val);
        
        return cur;
    }
    
    bool isValidBST(TreeNode* root) {
        return is_valid(root)[2];
    }
};