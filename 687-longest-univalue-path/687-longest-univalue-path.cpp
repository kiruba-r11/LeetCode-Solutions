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
    pair <int , int> solve(TreeNode* root , int &ans) {
    
        if(!root) return {-1e4 , -1};
        if(!root->left && !root->right) {
            return {root->val , 0};
        }
        
        pair <int , int> l = solve(root->left , ans);
        pair <int , int> r = solve(root->right , ans);
        
        pair <int , int> c;
        
        if(l.first == root->val && r.first == root->val) {
            ans = max(ans , 2 + r.second + l.second);
        }
        if(l.first == root->val) {
            ans = max(ans , 1 + l.second);
        }
        if(r.first == root->val) {
            ans = max(ans , 1 + r.second);
        }
        
        if(l.first == root->val && r.first == root->val) {
            c = {root->val , max(l.second , r.second) + 1};
        } else if(l.first == root->val) {
            c = {root->val , 1 + l.second};
        } else if(r.first == root->val) {
            c = {root->val , 1 + r.second};
        } else {
            c = {root->val , 0};
        }
        
        return c;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        solve(root , ans);
        return ans;
    }
};