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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        ListNode* headptr = newHead;
        
        while(head) {
            ListNode* curHead = head;
            int sum = 0;
            while(head->next && head->next->val != 0) {
                sum += head->next->val;
                head = head->next;
            }
            head = head->next;
            curHead->val = sum;
            curHead->next = head;
            
            if(sum != 0) {
                newHead->next = curHead;
                newHead = newHead->next;
            } else {
                newHead->next = NULL;
            }
        }
        
        return headptr->next;
    }
};