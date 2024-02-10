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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        depth--;
        int level = 1;
        queue <TreeNode*> q;
        q.push(root);
        bool check = false;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(level == depth) {
                    TreeNode* node1 = new TreeNode(val);
                    TreeNode* node2 = new TreeNode(val);
                    
                    TreeNode* nl = node->left;
                    TreeNode* nr = node->right;
                    
                    node1->left = nl;
                    node2->right = nr;
                    
                    node->left = node1;
                    node->right = node2;
                    
                    check = true;
                }
                
                if(!check) {
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};