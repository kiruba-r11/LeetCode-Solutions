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
    int ans = -1;
    int deep = -1;
    bool bottom(TreeNode* root , int depth) {
        if(!root) return false;
        if(!root->left && !root->right) {
            if(depth > deep) {
                deep = depth;
                ans = root->val;
                return true;
            }
            return false;
        }
        
        bool left = bottom(root->left , depth + 1);
        bool right = bottom(root->right , depth + 1);
        
        return left || right;
    }
    int findBottomLeftValue(TreeNode* root) {
        bottom(root , 0);
        return ans;
    }
};