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
        ListNode* temp = newHead;
        head = head->next;
        while(head) {
            int sum = 0;
            while(head->val != 0) {
                sum += head->val;
                head = head->next;
            }
            if(sum != 0) {
                head->val = sum;
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        temp->next = NULL;
        return newHead->next;
    }
};