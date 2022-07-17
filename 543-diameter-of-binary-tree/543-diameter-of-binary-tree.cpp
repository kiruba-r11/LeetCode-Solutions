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
    pair <int , int> solve(TreeNode* root) {
        if(!root) return {-1 , -1};
        
        pair <int , int> left = solve(root->left);
        pair <int , int> right = solve(root->right);
        
        int height = max(left.first , right.first) + 1;
        int dia = max(max(left.second , right.second) , max((left.first + right.first + 2) , height));
        
        return {height , dia};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).second;
    }
};