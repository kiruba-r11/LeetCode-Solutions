class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        /*
        
        O(nlogn) time and O(n) space complexity
        
        Idea - Use deque to perform the operation on indices (instead of element) as mentioned. This indices represent where the element of deck should exist in the result
        
        */
        
        deque <int> dq;
        int j = 0 , n = deck.size();
        
        // Store all the indices in the deque
        for(int i = 0; i < n; i++) {
            dq.push_back(i);
        }
        
        vector <int> ans(n);
        sort(deck.begin() , deck.end());
        
        while(!dq.empty()) {
            
            // The deque front index represents current element of deck should exist here
            ans[dq.front()] = deck[j];
            j++;
            dq.pop_front();
            
            if(!dq.empty()) {
                
                // Pop the front index now and push it back
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        
        return ans;
    }
};