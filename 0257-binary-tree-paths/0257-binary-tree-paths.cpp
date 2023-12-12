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
    vector <string> ans;
    
    void solve(TreeNode* root , string &cur) {
        if(!root) return;
        if(!root->left && !root->right) {
            ans.push_back(cur + to_string(root->val));
            return;
        }
        
        string temp = cur;
        cur += to_string(root->val) + "->";
        solve(root->left , cur);
        solve(root->right , cur);
        cur = temp;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string cur = "";
        solve(root , cur);
        return ans;
    }
};