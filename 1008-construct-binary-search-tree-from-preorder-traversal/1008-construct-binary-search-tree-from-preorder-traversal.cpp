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
    unordered_map <int , int> hash;
    TreeNode* build(vector <int> &pre , vector <int> &in , int &i , int start , int end) {
        if(i == pre.size() || start > end) return NULL;
        
        TreeNode* root = new TreeNode(pre[i]);
        int idx = hash[pre[i]];
        i++;
        
        root->left = build(pre , in , i , start , idx - 1);
        root->right = build(pre , in , i , idx + 1 , end);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector <int> inorder = preorder;
        sort(inorder.begin() , inorder.end());
        
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            hash[inorder[i]] = i;
        }
        
        int idx = 0;
        return build(preorder , inorder , idx , 0 , n - 1);
    }
};