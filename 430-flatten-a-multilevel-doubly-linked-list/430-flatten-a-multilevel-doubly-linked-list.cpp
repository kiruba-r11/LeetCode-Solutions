/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void solve(Node* head) {
    
        if(!head) return;
        
        while(head) {
            if(!head->child) head = head->next;
            else {
                
                solve(head->child);
                
                Node* start = head;
                Node* nstart = start->child;
                Node* child = nstart;
                start->child = NULL;
                
                while(nstart && nstart->next) {
                    nstart = nstart->next;
                }
                
                nstart->next = start->next;
                if(start->next) start->next->prev = nstart;
                
                head = start->next;
                start->next = child;
                child->prev = start;
            }
        }
        
    }
    
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};