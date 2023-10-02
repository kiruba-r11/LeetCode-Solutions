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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list1;
        int idx = 0;
        
        ListNode* tail = list2;
        while(tail && tail->next) {
            tail = tail->next;
        }
        
        while(ptr2) {
            if(idx + 1 == a) {
                ptr2 = ptr1->next;
                ptr1->next = list2;
            }
            if(idx + 1 == b) {
                tail->next = ptr2->next;
            }
            
            if(idx + 1 < a) ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            idx++;
        }
        
        return list1;
    }
};