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
    
    bool isBST(TreeNode* root , long long leftRange , long long rightRange) {
        if(root == NULL) return true;
        
        if(root->val <= leftRange || root->val >= rightRange) return false;
        
        bool left = isBST(root->left , leftRange , root->val);
        if(!left) return false;
        
        bool right = isBST(root->right , root->val , rightRange);
        if(!right) return false;

        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        /*
        
        O(N) time and space (recursive stack) complexity
        
        */
        return isBST(root , LLONG_MIN , LLONG_MAX);   
    }
};