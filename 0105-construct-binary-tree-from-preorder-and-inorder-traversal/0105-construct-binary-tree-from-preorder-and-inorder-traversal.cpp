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
    
    bool isinrange(vector <int> &in , int start , int end , int elem) {
        for(int i = start; i <= end; i++) {
            if(in[i] == elem) return true;
        }
        return false;
    }
    
    TreeNode* build(vector <int> &pre , vector <int> &in , int &i , int start , int end) {
        
        if(i == pre.size()) return NULL;
        
        bool range = isinrange(in , start , end , pre[i]);
        if(range) {
            TreeNode* node = new TreeNode(pre[i]);
            int idx = hash[pre[i]];
            i++;
            node->left = build(pre , in , i , start , idx - 1);
            node->right = build(pre , in , i , idx + 1 , end);
            
            return node;
        }
        
        return NULL;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            hash[inorder[i]] = i;
        }
        int idx = 0;
        return build(preorder , inorder , idx , 0 , n - 1);
    }
};