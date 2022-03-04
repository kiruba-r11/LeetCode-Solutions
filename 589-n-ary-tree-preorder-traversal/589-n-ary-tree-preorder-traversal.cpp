/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preOrder(Node* root , vector <int> &pre) {
        if(root == NULL) return;
        
        pre.push_back(root->val);
        
        for(auto child: root->children) {
            preOrder(child , pre);     
        }
    }
    
    vector<int> preorder(Node* root) {
        
        /*
    
        O(N) time and O(H) space (stack) complexity

        */
        
        vector <int> pre;
        
        preOrder(root , pre);
        
        return pre;
    }
};














