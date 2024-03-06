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
    // states ->
    //          -1 -> Needs a camera
    //           0 -> Buys a camera
    //           1 -> Already covered, no need of camera
    
    int camera = 0;
    int solve(TreeNode* root) {
        if(!root) return 1;
        if(!root->left && !root->right) return -1;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left == -1 || right == -1) {
            camera++;
            return 0;
        } 
        if(left == 1 && right == 1) return -1;
        return 1;
    }
    
    int minCameraCover(TreeNode* root) {
        if(solve(root) == -1) camera++;
        return camera;
    }
};