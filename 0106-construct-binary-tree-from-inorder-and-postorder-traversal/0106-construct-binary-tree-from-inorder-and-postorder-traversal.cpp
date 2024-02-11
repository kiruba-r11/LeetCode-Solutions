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
    
    TreeNode* build(vector <int> &in , vector <int> &post , int &i , int start , int end) {
        if(i == -1 || start > end) return NULL;
        
        TreeNode* node = new TreeNode(post[i]);
        int idx = hash[post[i]];
        i--;
        
        node->right = build(in , post , i , idx + 1 , end);
        node->left = build(in , post , i , start , idx - 1);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            hash[inorder[i]] = i;
        }
        
        int idx = n - 1;
        return build(inorder , postorder , idx , 0 , n - 1);
    }
};