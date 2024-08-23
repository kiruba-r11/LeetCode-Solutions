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
    // 1 -> have a camera
    // 0 -> covered by a camera
    // -1 -> not covered by a camera
    int camera = 0;
    int solve(TreeNode* root) {
        if(!root) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        int cur = -2;
        
        if(left + right >= 1) {
            cur = 0;
        } else if(left == 0 && right == 0) {
            cur = -1;
        } else {
            camera++;
            cur = 1;
        }
        
        return cur; 
    }
    
    int minCameraCover(TreeNode* root) {
        if(solve(root) == -1) camera++;
        return camera;
    }
};