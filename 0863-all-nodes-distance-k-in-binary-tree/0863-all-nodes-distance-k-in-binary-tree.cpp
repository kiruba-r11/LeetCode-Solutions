/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector <TreeNode*> nodeToRootPath(TreeNode* root , TreeNode* target) {
        if(!root) return {};
        if(root == target) return {root};
        
        vector <TreeNode*> left = nodeToRootPath(root->left , target);
        vector <TreeNode*> right = nodeToRootPath(root->right , target);
        
        if(!left.size() && !right.size()) return {};
        if(!left.size()) {
            right.push_back(root);
            return right;
        }
        if(!right.size()) {
            left.push_back(root);
            return left;
        }
        return {};
    }
    
    void findKDown(TreeNode* root, int block , int dist , vector <int> &ans) {
        
        if(!root) return;
        if(root->val == block) return;
        if(dist == 0) ans.push_back(root->val);
        
        findKDown(root->left , block , dist - 1 , ans);
        findKDown(root->right , block , dist - 1 , ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector <TreeNode*> nodes = nodeToRootPath(root , target);
        int n = nodes.size();
        
        vector <int> ans;
        for(int i = 0; i < n; i++) {
            findKDown(nodes[i] , i == 0 ? -1 : nodes[i - 1]->val , k - i , ans);
        }
        return ans;
    }
};