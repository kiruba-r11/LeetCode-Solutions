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
    void paths(TreeNode* root , string &cur , vector <string> &ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            ans.push_back(cur + to_string(root->val));
            return;
        }
        
        string temp = cur;
        cur += to_string(root->val) + "->";
        paths(root->left , cur , ans);
        paths(root->right , cur , ans);
        cur = temp;
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> ans;
        string cur = "";
        paths(root , cur , ans);
        return ans;
    }
};