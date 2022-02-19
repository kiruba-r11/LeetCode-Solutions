class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        /*
        
        O(NlogNlogM) time and O(N) space complexity
        
        1. N -> No. of elements in the array
        2. Using a priority queue, takes O(N) space and O(NlogN) time to order itself
        3. Now, a particular element 'M' will stay in the queue, till it is odd. And at each step, it is divided by 2. Which basically derives to logM
        
        Idea -> Priority Queue
        
        Intuition:  
            * Given operations:
                1. If num is odd, multiply it by 2.
                2. If num is even, divide it by 2.
                
            * Breaking down operations:
                1. If num is odd, after multiplying it with two, gives us an even element. So, for an odd element the operation can be applied only once.
                2. If num is even, we can divide it any arbitary number of times till it gives us an odd number.
                
            * Conclusions:
                1. An odd number can be increased once.
                2. An even number can be decreased till it reaches odd.
                3. The maximum deviation can be obtained by subtracting the largest and smallest number. And to minimum it, we either have to increase the minimum element, or decrease the maximum element.
                
            * Working:
                1. Let's make all the elements in the array as even, so that our goal simplifies, and now we need to just minimise the maximum element.
                
                2. For every maximum element:
                    2.1. If the element is even, let's divide it by 2, and replace.
                    2.2. If the element is odd, stop the process, since odd elements cannot be decreased 
                    2.3. Also, we make sure to update the minimum element.
                    
                3. Reason for stopping when the maximum element is odd:
                    3.1. When maximum element is odd, we cannot decrease it furthur. 
                    3.2. Now, if maximum can't be decreased, then minimum can be increased to minimise the deviation.
                    3.3. But, if minimum is even, it can only be decreased (not increased). Hence it is not possible 
                    3.4. If minimum is odd, it can be increased. But note that, we started the process with all even elements. Now, how come we got an odd element. We got it because we decreased the even elements. Which basically means, this element would have contributed to our answer, so that we can safely say that, we cannot increase the minimum element.
        
        */
        
        int n = nums.size();
        int minElem = INT_MAX;
        int res = INT_MAX;
        
        priority_queue <int> pq;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] & 1) nums[i] *= 2;
            minElem = min(minElem , nums[i]);
            pq.push(nums[i]);
        }
        
        while(pq.top() % 2 == 0) {
            int curTop = pq.top();
            res = min(res , curTop - minElem);
            minElem = min(minElem , curTop / 2);
            pq.pop();
            pq.push(curTop / 2);
        }
        
        res = min(res , pq.top() - minElem);
        
        return res;
        
    }
};