
/*

O(1) time for each operation
O(N) space complexity 

Idea -> 
    1. Find the frequency of every element
    2. For each and every frequency maintain a separate stack
    3. Return the topmost element of stack with max frequency

*/

class FreqStack {
public:
    // To store the frequency of the integers
    unordered_map <int , int> hashInt;
    
    // To store the stack with elements of given frequency
    unordered_map <int , stack <int>> hashStack;
    
    // To store the current max frequency
    int maxFreq;
    
    FreqStack() {
        
        maxFreq = 0;
        
    }
    
    // O(1) operation
    void push(int val) {
        
        // Update the frequency for this integer
        hashInt[val]++;
        
        // Update the max frequency
        maxFreq = max(maxFreq , hashInt[val]);
        
        // Update this element to the stack for given frequency
        hashStack[hashInt[val]].push(val);
    }
    
    // O(1) operation
    int pop() {
        
        // Store the topmost element of stack with max frequency and remove it
        int elem = hashStack[maxFreq].top();
        hashStack[maxFreq].pop();
        
        // Update the frequency of this integer
        hashInt[elem]--;
        
        // Update the max frequency if the stack becomes empty for this current max frequency
        if(hashStack[maxFreq].empty()) maxFreq--;
        
        // Return the result
        return elem;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */