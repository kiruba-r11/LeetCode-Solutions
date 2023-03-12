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
    ListNode* mergeSorted(ListNode* h1 , ListNode* h2) {
    
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        
        while(h1 && h2) {
            if(h1->val <= h2->val) {
                temp->next = h1;
                temp = h1;
                h1 = h1->next;
                temp->next = NULL;
            } else {
                temp->next = h2;
                temp = h2;
                h2 = h2->next;
                temp->next = NULL;
            }
        }
        
        while(h1) {
            temp->next = h1;
            temp = h1;
            h1 = h1->next;
            temp->next = NULL;
        }
        
        while(h2) {
            temp->next = h2;
            temp = h2;
            h2 = h2->next;
            temp->next = NULL;
        }
        
        return head->next;
    }
    
    void solve(vector <ListNode*> &lists , int index) {
    
        if(index == lists.size() - 1) return;
        solve(lists , index + 1);
        
        lists[index] = mergeSorted(lists[index] , lists[index + 1]);
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        solve(lists , 0);
        return lists[0];
    }
};