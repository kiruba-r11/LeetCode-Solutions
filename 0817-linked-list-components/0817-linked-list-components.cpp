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
    int numComponents(ListNode* head, vector<int>& nums) {
        int connect = 0;
        
        unordered_map <int , int> hash;
        for(auto i: nums) hash[i]++;
        
        ListNode* temp = head;
        while(temp) {
            bool enter = false;
            while(temp && hash[temp->val] != 0) {
                enter = true;
                temp = temp->next;
            }
            if(enter) connect++;
            if(temp) temp = temp->next;
        }
        
        return connect;
    }
};