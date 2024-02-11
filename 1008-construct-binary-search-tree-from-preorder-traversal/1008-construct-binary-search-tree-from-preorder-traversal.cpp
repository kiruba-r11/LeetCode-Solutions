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
    TreeNode* build(vector <int> &pre , int &i , int start , int end) {
    
        if(i == pre.size() || pre[i] < start || pre[i] > end) return NULL;
        
        TreeNode* root = new TreeNode(pre[i]);
        i++;
        
        root->left = build(pre , i , start , root->val);
        root->right = build(pre , i , root->val , end);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder , i , INT_MIN , INT_MAX);
    }
};