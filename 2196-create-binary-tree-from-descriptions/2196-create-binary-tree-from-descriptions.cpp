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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map <int , bool> child;
        int n = des.size();
        for(int i = 0; i < n; i++) {    
            child[des[i][1]] = true;
        }
        
        unordered_map <int , TreeNode*> hash;
        for(int i = 0; i < n; i++) {
            if(hash.find(des[i][0]) == hash.end()) {
                hash[des[i][0]] = new TreeNode(des[i][0]);
            } 
            if(hash.find(des[i][1]) == hash.end()) {
                hash[des[i][1]] = new TreeNode(des[i][1]);
            }
            
            if(des[i][2]) hash[des[i][0]]->left = hash[des[i][1]];
            else hash[des[i][0]]->right = hash[des[i][1]];
        }
        
        for(auto i: hash) {
            if(child.find(i.first) == child.end()) return hash[i.first];
        }
        return NULL;
    }
};