class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int i = 0 , j = 0 , ans = n + 1;
        map <int , int> hash;
        
        while(j < n) {
            hash[cards[j]]++;
            while(hash[cards[j]] > 1) {
                if(hash[cards[j]] <= 2 && cards[i] == cards[j]) break;
                hash[cards[i]]--;
                i++;
            }
            if(hash[cards[j]] == 2) ans = min(ans , j - i + 1);
            j++;
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};