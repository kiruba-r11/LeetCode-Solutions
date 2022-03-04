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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Fast and Slow pointer with distance n
        
        */
        
        ListNode* fast = head;
        ListNode* slow = NULL;
        
        while(n-- > 1) {
            fast = fast->next;
        }
        
        while(fast && fast->next) {
            fast = fast->next;
            
            if(!slow) slow = head;
            else slow = slow->next;
        }
        
        ListNode* temp = NULL;
        
        if(slow) temp = slow->next;
        else temp = head;
        
        if(slow) slow->next = temp->next;
        else head = temp->next;
        delete temp;
        
        return head;
    }
};