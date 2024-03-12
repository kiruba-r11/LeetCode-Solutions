/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        Node* level = root;
        while(level != NULL) {
            Node* temp = level;
            while(level) {
                if(level->left) level->left->next = level->right;
                if(level->right && level->next) level->right->next = level->next->left;
                level = level->next;
            }
            level = temp->left;
        }
        
        return root;
    }
};