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
    TreeNode* solve(vector <int> &preorder , vector <int> &inorder , int start , int end , int &index , map <int , int> &hash) {
        if(index == preorder.size() || start >= end) return NULL;

        int newStart = hash[preorder[index]] + 1;
        int newEnd = hash[preorder[index]];
        
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        
        root->left = solve(preorder , inorder , start , newEnd , index , hash);
        root->right = solve(preorder , inorder , newStart , end , index , hash);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        map <int , int> hash;
        for(int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        return solve(preorder , inorder , 0 , preorder.size() , index , hash);
    }
};