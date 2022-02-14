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
    
    int findMaxDepth(TreeNode* root) {
        // 1. Base Case 
        // When there is no node, the depth is zero
        if(root == NULL) return 0;
        
        // 2. Hypothesis
        // Find the max depth of left sub tree
        int leftMaxDepth = findMaxDepth(root->left);
        // Find the max depth of right sub tree
        int rightMaxDepth = findMaxDepth(root->right);
        
        // 3. Induction
        // Take the max depth of both sub tree and add one to represent the inclusion current node
        return max(leftMaxDepth , rightMaxDepth) + 1;
    }
    int maxDepth(TreeNode* root) {
        
        /*
        
        O(N) time and space (recursion call stack) complexity
        Idea -> Recursion (IBH)
        
        */
        
        return findMaxDepth(root);
        
    }
};