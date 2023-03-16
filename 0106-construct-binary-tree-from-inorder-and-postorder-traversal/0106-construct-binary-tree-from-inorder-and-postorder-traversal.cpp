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
    TreeNode* solve(vector <int> &inorder , vector <int> &postorder , int start , int end , int &index , map <int , int> &hash) {
        if(index < 0 || start > end) return NULL;
        
        int newStart = hash[postorder[index]] + 1;
        int newEnd = hash[postorder[index]] - 1;
        
        TreeNode* root = new TreeNode(postorder[index]);
        index--;
        
        root->right = solve(inorder , postorder , newStart , end , index , hash);
        root->left = solve(inorder , postorder , start , newEnd , index , hash);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        map <int , int> hash;
        for(int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        return solve(inorder , postorder , 0 , postorder.size() - 1 , index , hash);
    }
};