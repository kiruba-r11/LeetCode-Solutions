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
    
    ListNode* reorder(ListNode* head1 , ListNode* head2) {
        
        if(!head1) return head2;
        if(!head2) return head1;
        
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        
        temp->next = head1;
        temp = temp->next;
        ListNode* t = head1->next;
        temp->next = head2;
        temp = temp->next;
        
        temp->next = reorder(t , head2->next);
        
        return newHead->next;
    }
    
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast) {
            fast = fast->next;
            if(fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        head2 = reverse(head2);
        head = reorder(head , head2);
    }
};