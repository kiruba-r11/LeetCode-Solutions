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
    int player1 = 0;
    int traverse(TreeNode* root , int x) {
        if(!root) return 0;
        
        int left = traverse(root->left , x);
        int right = traverse(root->right , x);
        
        if(root->val == x) {
            player1 = max(player1 , max(left , right));
            return 0;
        }
        
        player1 = max(player1 , left + right + 1);
        return left + right + 1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        traverse(root , x);
        int player2 = n - player1;
        return player1 >= player2;
    }
};