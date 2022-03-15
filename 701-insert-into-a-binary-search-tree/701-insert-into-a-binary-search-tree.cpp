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
    TreeNode* insert(TreeNode* root , int val) {
    
        if(root == NULL) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        
        if(root->val > val) {
            root->left = insert(root->left , val);
        } else {
            root->right = insert(root->right , val);
        }
        
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        /*
        
        O(H) time and space (recursive stack) complexity
        H -> 
            1. Best Case - logN
            2. Worst Case - N
        
        */
        
        return insert(root , val);
    }
};