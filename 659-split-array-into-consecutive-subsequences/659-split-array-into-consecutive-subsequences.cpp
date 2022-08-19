class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        /*
        
        Time Complexity : O(n)
        Space Complexity : O(n)
        
        Approach : Hashing
        
        */
        
        unordered_map <int , int> freq , need;
        
        for(auto i: nums) freq[i]++;
        
        for(auto i: nums) {
            
            // If all the occurences of this current number is taken
            if(freq[i] == 0) continue;
            
            // This represents that there is an existing sequence with length greater than or equal to 3 with last element in the sequence as i - 1, and requires and element i to extend the sequence.
            if(need[i] != 0) {
                
                // Remove this dependancy and occurence as the sequence is now extended
                need[i]--;
                freq[i]--;
                
                // Add the next number into the dependancy of extending the sequence
                need[i + 1]++;
            }
            
            // This represents that there are atleast 3 elements to create a new sequence
            else if(freq[i] != 0 && freq[i + 1] != 0 && freq[i + 2] != 0) {
                freq[i]--;
                freq[i + 1]--;
                freq[i + 2]--;
                
                // Add the dependancy to extend this sequence
                need[i + 3]++;
            }
            
            // This represents that there is no sequence that can be extended for this current number, and there is no new sequence that can be created with this current number
            else {
                return false;
            }
            
        }
        
        return true;
    }
};