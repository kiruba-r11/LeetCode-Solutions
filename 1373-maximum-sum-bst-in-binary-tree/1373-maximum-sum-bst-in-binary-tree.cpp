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
    int sum = 0;
    int minval = -1e5;
    int maxval = 1e5;
    
    // state = {minnode, maxnode, is_bst , sum}
    vector <int> solve(TreeNode* root) {
        if(!root) return {maxval , minval , true , 0};
        // if(!root->left && !root->right) {
        //     sum = max(sum , root->val);
        //     return {root->val , root->val , true , root->val};
        // }
        
        vector <int> left = solve(root->left);
        vector <int> right = solve(root->right);
        
        vector <int> ans;
        
        int curmin = min(min(left[0] , right[0]) , root->val);
        int curmax = max(max(left[1] , right[1]) , root->val);
        
        // left and right are bst
        if(left[2] && right[2]) {
            // current root can be included in the bst
            if(root->val > left[1] && root->val < right[0]) {
                ans = {curmin , curmax , true , root->val + left[3] + right[3]}; 
                sum = max(sum , max(left[3] , right[3]));
                sum = max(sum , root->val + left[3] + right[3]);
            } else { // current root cannot be included in the bst
                ans = {curmin , curmax , false , max(left[3] , right[3])};
            }
        } else {
            ans = {curmin , curmax , false , max(left[3] , right[3])};
        }
        
        return ans;
    }
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return sum;
    }
};