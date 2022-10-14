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
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == NULL) {
            // delete head;
            return NULL;
        }
        
        ListNode *slow = NULL , *fast = head;
        
        while(fast != NULL) {
            fast = fast->next;
            
            if(fast) {
                fast = fast->next;
                if(slow) slow = slow->next;
                else slow = head;
            }
        }

        fast = slow->next;
        slow->next = fast->next;
        // delete fast;
        
        return head;
        
    }
};