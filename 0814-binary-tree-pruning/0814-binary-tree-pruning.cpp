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
    pair <int , int> prune(TreeNode* root) {
        if(!root) return {0 , 0};
        if(!root->left && !root->right) {
            if(root->val == 0) return {1 , 1};
            return {1 , 0};
        }
        
        pair <int , int> left = prune(root->left);
        pair <int , int> right = prune(root->right);
        
        int leftcnt = left.first;
        int leftzero = left.second;
        int rightcnt = right.first;
        int rightzero = right.second;
        
        if(left.first == left.second) {
            root->left = NULL;
            leftcnt = 0;
            leftzero = 0;
        }
        
        if(right.first == right.second) {
            root->right = NULL;
            rightcnt = 0;
            rightzero = 0;
        }
        
        return {leftcnt + rightcnt + 1 , leftzero + rightzero + root->val == 0};
    }
    TreeNode* pruneTree(TreeNode* root) {
        pair <int , int> ans = prune(root);
        if(root->val == 0) {
            if(ans.first == ans.second) return NULL;
        }
        return root;
    }
};