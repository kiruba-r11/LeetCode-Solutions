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
    int prei = 0 , posti = 0;
    TreeNode* build(vector <int> &pre , vector <int> &post) {
        TreeNode* node = new TreeNode(pre[prei++]);    
        if(node->val != post[posti]) node->left = build(pre , post);
        if(node->val != post[posti]) node->right = build(pre , post);
        posti++;
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder , postorder);
    }
};