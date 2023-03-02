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
    map <string , pair <TreeNode* , int>> hash;
    
    string solve(TreeNode* root) {
    
        if(root == NULL) return "";
        
        string left = solve(root->left);
        string right = solve(root->right);
        
        string cur = "(" + left + ")" + to_string(root->val) + "(" + right + ")";
        
        if(hash.find(cur) == hash.end()) {
            hash[cur] = {root , 1};
        } else {
            hash[cur] = {root , 2};
        }
        
        return cur;    
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        
        vector <TreeNode*> ans;
        for(auto i: hash) {
            if(i.second.second > 1) {
                ans.push_back(i.second.first);
            }
        }
        
        return ans;
    }
};