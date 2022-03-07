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
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Space Optimised BFS
        
            1. This approach works only if the tree is complete
            2. Consider the tree (Intially):

                                a-> NULL

                        b               c-> NULL

                    d       e        f       g->NULL
            
            3. Let cur = root, Now cur->left->next = cur->right (Making the left next point to right)
            4. And if cur->next exists, Then cur->right->next = cur->left->next (Making the right next to point to left)
            5. Then cur = cur->next (Moving to next node in the same level)
            6. root = root->left , cur = root (Moving to next level)


        
        The intuition is that, because of the next pointer, we can travel to complete level. 
        Ans since we also have a pointer to the start node of the level, we do not require a queue to perform BFS.
        
        */
        
        if(root == NULL) return NULL;
        
        Node* tempRoot = root;
        Node* cur;
        
        while(tempRoot != NULL) {
            cur = tempRoot;
            while(cur != NULL) {
                if(cur->left) cur->left->next = cur->right;
                if(cur->left && cur->next) cur->right->next = cur->next->left;

                // Moving to the next node of same level
                cur = cur->next;
            }
            // Moving to the start of next level
            tempRoot = tempRoot->left;
        }
        
        return root;
    }
};




