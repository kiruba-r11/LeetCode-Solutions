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
    int count = 0;
    pair <int , int> subtree(TreeNode* root) {
        if(!root) return {0 , 0};
        
        pair <int , int> left = subtree(root->left);
        pair <int , int> right = subtree(root->right);
        
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        
        if(sum / cnt == root->val) count++;
        
        return {sum , cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        subtree(root);
        return count;
    }
};