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
    // {sum that can be extended, sum that cannot be extended}
    pair <int , int> pathsum(TreeNode* root) {
        if(!root) return {-1001 , -1001};
        if(!root->left && !root->right) return {root->val , root->val};
        
        pair <int , int> left = pathsum(root->left);
        pair <int , int> right = pathsum(root->right);
        
        pair <int , int> ans;
        
        ans.first = max(root->val , max(left.first , right.first) + root->val);
        ans.second = max(left.first + right.first + root->val , 
                     max(max(left.first , right.first) , 
                         max(left.second , right.second)));
        
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        pair <int , int> ans = pathsum(root);
        return max(ans.first , ans.second);
    }
};