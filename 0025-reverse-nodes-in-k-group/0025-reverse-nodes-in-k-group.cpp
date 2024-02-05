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
    ListNode* reverseK(ListNode* head , int k) {
        
        if(!head || !head->next || k == 1) return head;
        
        ListNode* temp = head;
        for(int i = 0; i < k - 1 && temp; i++) {
            temp = temp->next;
        }
        
        ListNode* nextHead = NULL;
        if(temp) {
            nextHead = temp->next;
            temp->next = NULL;
            ListNode* newHead = reverse(head);
            head->next = reverseK(nextHead , k);
            return newHead;
        }
        
        return head;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseK(head , k);
    }
};