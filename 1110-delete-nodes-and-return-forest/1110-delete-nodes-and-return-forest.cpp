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
    vector <TreeNode*> ans;
    TreeNode* del(TreeNode* root , unordered_map <int , bool> &to_del) {
        if(!root) return NULL;
        if(!root->left && !root->right) {
            if(to_del.find(root->val) != to_del.end()) {
                return NULL;
            }
            return root;
        }
        
        root->left = del(root->left , to_del);
        root->right = del(root->right , to_del);
        
        if(to_del.find(root->val) != to_del.end()) {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
        
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map <int , bool> to_del;
        for(auto i: to_delete) {
            to_del[i] = true;
        }
        
        root = del(root , to_del);
        if(root) ans.push_back(root);
        return ans;
    }
};