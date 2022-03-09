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
    ListNode* removeElements(ListNode* head, int val) {
        
        /*
        
        O(N) time and O(1) space complexity
        
        */
        
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        
        while(head) {
            if(head->val != val) {
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        temp->next = NULL;
        return newHead->next;
    }
};