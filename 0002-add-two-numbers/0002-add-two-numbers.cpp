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
    void solve(ListNode* temp , ListNode* l1 , ListNode* l2 , int carry) {
    
        if(!l1 && !l2) {
            if(carry != 0) {
                ListNode* newnode = new ListNode(carry);
                temp->next = newnode;
            }
        } else if(!l1) {
            int sum = l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            l2->val = sum;
            temp->next = l2;
            solve(temp->next, l1 , l2->next , carry);
        } else if(!l2) {
            int sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            l1->val = sum;
            temp->next = l1;
            solve(temp->next, l1->next , l2 , carry);
        } else {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            l1->val = sum;
            temp->next = l1;
            solve(temp->next , l1->next , l2->next , carry);
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(-1);
        ListNode* head = newHead;
        
        solve(head , l1 , l2 , 0);
        return newHead->next;
    }
};
