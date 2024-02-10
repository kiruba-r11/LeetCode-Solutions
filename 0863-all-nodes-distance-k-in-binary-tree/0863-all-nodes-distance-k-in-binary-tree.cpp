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
    void dfs(TreeNode* root , unordered_map <int , vector <int>> &graph) {
        if(!root) return;
        
        graph[root->val];
        if(root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        
        dfs(root->left , graph);
        dfs(root->right , graph);
    }
    
    vector <int> ans;
    
    void distance(unordered_map <int , vector <int>> &graph , int src , int k , unordered_map <int , bool> &visited) {
        if(k == 0) {
            ans.push_back(src);
            return;
        }
        
        visited[src] = true;
        for(auto adj: graph[src]) {
            if(!visited[adj]) distance(graph , adj , k - 1 , visited);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <int , vector <int>> graph;
        dfs(root , graph);
        
        unordered_map <int , bool> visited;
        distance(graph , target->val , k , visited);
        
        return ans;
    }
};