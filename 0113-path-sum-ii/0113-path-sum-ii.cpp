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
    vector <vector <int>> ans;
    void path(TreeNode* root , int &target , vector <int> &cur) {
        
        if(!root) return;
        if(!root->left && !root->right) {
            if(target == root->val) {
                cur.push_back(root->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            
            return;
        }
        
        target -= root->val;
        cur.push_back(root->val);

        path(root->left , target , cur);
        path(root->right , target , cur);

        cur.pop_back();
        target += root->val;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <int> cur;
        path(root , targetSum , cur);
        return ans;
    }
};