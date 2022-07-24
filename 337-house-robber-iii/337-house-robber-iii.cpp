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
    int solve(TreeNode* root , bool robbed , map <pair <TreeNode* , bool> , int> &hash) {
        
        if(!root) return 0;
        int rob = 0 , notRob = 0;
        
        if(hash.find({root , robbed}) != hash.end()) return hash[{root , robbed}];
        
        notRob = solve(root->left , false , hash) + solve(root->right , false , hash);
        if(!robbed) rob = root->val + solve(root->left , true , hash) + solve(root->right , true , hash);
        
        return hash[{root , robbed}] = max(rob , notRob);
    }
    int rob(TreeNode* root) {
        map <pair <TreeNode* , bool> , int> hash;
        
        return solve(root , false , hash);
    }
};