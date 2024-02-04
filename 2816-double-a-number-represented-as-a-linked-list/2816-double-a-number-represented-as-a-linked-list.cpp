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
    
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* temp = head;
        ListNode* tail = NULL;
        int carry = 0;
        while(temp) {
            int sum = carry + temp->val * 2;
            carry = sum / 10;
            sum = sum % 10;
            
            temp->val = sum;
            tail = temp;
            temp = temp->next;
        }
        
        if(carry) tail->next = new ListNode(carry);
        head = reverse(head);
        return head;
    }
};