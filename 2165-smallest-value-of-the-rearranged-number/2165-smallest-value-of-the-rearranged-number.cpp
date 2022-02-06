class Solution {
public:
    
    static bool cmp(pair <int , int> &a , pair <int , int> &b) {
        return a.first < b.first;
    }
    
    void helper(vector <pair <int , int>> &s , long long &ans) {
        
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < s[i].second; j++) {
                ans = ans * 10 + s[i].first;
            }
        }
        
    }
    
    long long smallestNumber(long long num) {
        
        /*
        
        O((logN) * log(logN)) time and O(logN) space complexity
        Idea -> Sorting and Hashing
        
        */
        
        if(num == 0) return 0;
        
        long long n = num;
        if(n < 0) n *= -1;
    
        // Store all the digits of the number with its count
        map <int , int> hash;
        while(n > 0) {
            hash[n % 10]++;
            n /= 10;
        }
    
        // Convert the hashmap into vector of pairs
        vector <pair <int , int>> s;
        for(auto i: hash) {
            s.push_back({i.first , i.second});
        }
        
        // If number is negative, then the result should be in descending order of digits
        if(num < 0) sort(s.rbegin() , s.rend() , cmp);
        // If number is positive, then the result should be in increasing order of digits (Except for a case where there is zero, the second smallest element should be at the start)
        else sort(s.begin() , s.end() , cmp);
        
        long long ans = 0;
        
        if(num < 0 || s[0].first != 0) {
            
            // Forming the array into a number
            helper(s , ans);
            
            if(num < 0) ans *= -1;
        } else {
            // If zero is present, then the first element should be the second smallest number
            ans = ans * 10 + s[1].first;
            s[1].second--;

            // Forming the array into a number
            helper(s , ans);
        }
        
        return ans;
    }
};