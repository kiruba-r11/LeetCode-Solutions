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
    bool isMirror(TreeNode* root1 , TreeNode* root2) {
        
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        
        if(root1->val != root2->val) return false;
        
        bool left = isMirror(root1->left , root2->right);
        bool right = isMirror(root1->right , root2->left);
        
        return left && right;
    }
    
    bool isSymmetric(TreeNode* root) {
        
        /*
        
        O(N) time and space (recursion stack) complexity
        Idea -> A tree is symmetric if it is mirror to itself
        
        */
        
        return isMirror(root , root);
    }
};