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
    TreeNode* search(TreeNode* root , int val) {
    
        if(root == NULL) return root;
        
        if(root->val == val) return root;
        
        if(root->val > val)
            return search(root->left , val);
        return search(root->right , val);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        /*
        
        O(H) time and space (recursive stack) complexity
        H -> 
            Best Case - logN 
            Worst Case - N
        
        */
        
        return search(root , val);
    }
};