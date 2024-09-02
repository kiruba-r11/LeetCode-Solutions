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
    pair <int , int> solve(TreeNode* root) {
        if(!root) return {-1001 , -1001};
        
        pair <int , int> left = solve(root->left);
        pair <int , int> right = solve(root->right);
        
        pair <int , int> cur;
        cur.first = max(max(left.first , right.first) + root->val , root->val);
        cur.second = max(max(left.second , right.second) , left.first + right.first + root->val);
        
        ans = max(max(cur.first , cur.second) , ans);
        
        return cur;
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};