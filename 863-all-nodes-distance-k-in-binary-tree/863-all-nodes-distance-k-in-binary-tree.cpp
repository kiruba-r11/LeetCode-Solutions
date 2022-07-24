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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map <int , vector <int>> graph;
        
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left) {
                    q.push(node->left);
                    graph[node->val].push_back(node->left->val);
                    graph[node->left->val].push_back(node->val);
                }
                if(node->right) {
                    q.push(node->right);
                    graph[node->val].push_back(node->right->val);
                    graph[node->right->val].push_back(node->val);
                }
            }
        }
        
        map <int , bool> visited;
        vector <int> ans;
        
        queue <int> qq;
        qq.push(target->val);
        visited[target->val] = true;
        
        while(!qq.empty()) {
            int count = qq.size();
            if(k < 0) break;
            for(int it = 0; it < count; it++) {
                int node = qq.front();
                qq.pop();
                
                if(k == 0) ans.push_back(node);
                
                for(auto i: graph[node]) {
                    if(visited[i] == false) {
                        qq.push(i);
                        visited[i] = true;
                    }
                }
            }
            k--;
        }
        
        return ans;
    }
};