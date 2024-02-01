/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newHead = reverse(head->next);
            
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    
    /*
    8 -> 3 -> 13  2 -> 5
    prev = 8 , head = 3 , temp-> -1
    prev = 8 , head = 13 , temp-> -1->13-> 13
    prev = 13 , head = 2, temp-> -1 -> 13
    prev = 13 , head = 2, temp-> -1 -> 13
    prev = 13 , head = null, 
    
    */
    ListNode* remove(ListNode* head , ListNode* prev) {
        if(!head) {
            return NULL;
        }
        
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        
        if(prev->val <= head->val) {
            temp->next = head;
            temp = temp->next;
            temp->next = remove(head->next , head);
        }
        else {
            temp->next = remove(head->next , prev);
        }
        
        return newHead->next;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;
        
        head = reverse(head);
        head->next = remove(head->next , head);
        head = reverse(head);
        return head;
    }
};