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
    tuple <TreeNode* , int , int> solve(TreeNode* root) {
        if(!root) return {NULL , 0 , 0};
        
        tuple <TreeNode* , int , int> l = solve(root->left);
        tuple <TreeNode* , int , int> r = solve(root->right);
        
        int lc = get <1> (l);
        int lz = get <2> (l);
        int rc = get <1> (r);
        int rz = get <2> (r);
        
        int tc = lc + rc + 1;
        int tz = lz + rz;
        
        root->left = get <0> (l);
        root->right = get <0> (r);
        
        if(root->val == 0) {
            
            tz++;
            
            if(tc == tz) return {NULL , tc , tz};
            return {root , tc , tz};
        }
        
        return {root , tc , tz};
    }
    TreeNode* pruneTree(TreeNode* root) {
        tuple <TreeNode* , int , int> t = solve(root);
        return get <0> (t);
    }
};