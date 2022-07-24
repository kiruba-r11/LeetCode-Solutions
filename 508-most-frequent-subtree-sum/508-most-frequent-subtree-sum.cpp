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
    int solve(TreeNode* root , map <int , int> &hash) {
        if(!root) return 0;
        
        int lsum = solve(root->left , hash);
        int rsum = solve(root->right , hash);
        
        int csum = lsum + rsum + root->val;
        hash[csum]++;
        
        return csum;
    }
    
    static bool cmp(pair <int , int> &a , pair <int , int> &b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map <int , int> hash;
        solve(root , hash);
        
        vector <pair <int , int>> vp;
        for(auto i: hash) vp.push_back({i.first , i.second});
        
        sort(vp.begin() , vp.end() , cmp);
        
        vector <int> ans;
        ans.push_back(vp[vp.size() - 1].first);
        
        for(int i = vp.size() - 2; i >= 0; i--) {
            if(vp[i].second == vp[i + 1].second) ans.push_back(vp[i].first);
            else break;
        }
        
        return ans;
    }
};