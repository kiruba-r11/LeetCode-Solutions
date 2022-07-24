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
    TreeNode* solve(map <int , pair <int , int>> &hash , int node) {

        if(node < 1) return NULL;
        
        TreeNode* root = new TreeNode(node);
        root->left = solve(hash , hash[node].first);
        root->right = solve(hash , hash[node].second);
        
        return root;
    }
    
    
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        map <int , pair <int , int>> hash;
        map <int , bool> isChild;
        
        for(auto i: desc) {
            pair <int , int> t = {-1 , -1};
            
            if(hash[i[0]].first >= 1) t.first = hash[i[0]].first;
            if(hash[i[0]].second >= 1) t.second = hash[i[0]].second;
            
            if(i[2] == 1) hash[i[0]] = {i[1] , t.second};
            else hash[i[0]] = {t.first , i[1]};
            
            isChild[i[1]] = true;
            if(!isChild[i[0]]) isChild[i[0]] = false;
        }
        
        int parent = -1;
        for(auto i: isChild) {
            if(!i.second) parent = i.first;
        }
        
        TreeNode* root = solve(hash , parent);
        return root;
    }
};