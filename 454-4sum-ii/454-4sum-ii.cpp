class Solution {
public:
    
    // O(logN)
    int first_occurence(vector <int> &nums , int low , int high , int key) {
        
        // Storing an invalid index
        int ans = -1;
        
        // Binary Search
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            // If key is smaller, go to left half
            if(nums[mid] >= key) {
                
                // If key is found, store its index. 
                // Note -> It can be the first occurence, but its not always guaranteed so do not return it immediately
                if(nums[mid] == key) ans = mid;
                
                high = mid - 1;
            } 
            
            // If key is greater, go to right half 
            else {
                low = mid + 1;
            }
            
        }
        
        return ans;
    }
    
    // O(logN)
    
    int last_occurence(vector <int> &nums , int low , int high , int key) {
        
        // Storing the invalid index
        int ans = nums.size();
        
        // Binary Search
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            // If key is greater, go to right half
            if(nums[mid] <= key) {
                
                // If key is found, store its index. 
                // Note -> It can be the last occurence, but its not always guaranteed so do not return it immediately
                if(nums[mid] == key) ans = mid;
                
                low = mid + 1;
            }
            
            // If key is smaller, go to left half
            else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
//         /*
        
//         O(N^3 * logN) time and O(1) space
//         Idea -> For every triplet, binary search an element which gives the total sum of tuple as 0
        
//         // TLE, I really dont know WHY? 
        
//         */
        
//         // Sort the array
//         sort(nums1.begin() , nums1.end());
//         sort(nums2.begin() , nums2.end());
//         sort(nums3.begin() , nums3.end());
//         sort(nums4.begin() , nums4.end());
        
//         int n1 = nums1.size() , n2 = nums2.size() , n3 = nums3.size() , n4 = nums4.size() , count = 0;
        
//         // Iterate through the first array, for every element, check if there is a triplet
//         for(int i = 0; i < n1; i++) {
            
//             // Iterate through the second array, for every element, check if there is a pair
//             for(int j = 0; j < n2; j++) {
                
//                 // Iterate through the third array, for every element, check if there is an element
//                 for(int k = 0; k < n3; k++) {
                    
//                     int sum = nums1[i] + nums2[j] + nums3[k];
//                     int low = 0 , high = n4 - 1;
                    
//                     // Binary search the fourth array, which gives sum as 0 when added
                    
//                     // Find the last occurence using Binary Search
//                     int last = last_occurence(nums4 , low , high , -1 * sum);
                    
//                     // Find the first occurence using Binary Search
//                     int first = first_occurence(nums4 , low , high , -1 * sum);
                    
//                     // If the index is not invalid, add its count (a tuple is found)
//                     if(first != -1) count += last - first + 1;
//                 }
//             }
//         }
        
        /*
        
//         O(N^3) time and O(N) space
//         Idea -> For every triplet, find the count of the element in fourth array which gives the total sum of tuple as 0
        
//         // TLE, I really dont know WHY? 
        
//         */
        
//         // Sort the array
//         sort(nums1.begin() , nums1.end());
//         sort(nums2.begin() , nums2.end());
//         sort(nums3.begin() , nums3.end());
//         sort(nums4.begin() , nums4.end());
        
//         int n1 = nums1.size() , n2 = nums2.size() , n3 = nums3.size() , n4 = nums4.size() , count = 0;
//         unordered_map <int , int> hash;
        
//         // Store the occurences of elements in fourth array
//         for(int i = 0; i < n4; i++) {
//             hash[nums4[i]]++;
//         }
        
//         // Iterate through the first array, for every element, check if there is a triplet
//         for(int i = 0; i < n1; i++) {
            
//             // Iterate through the second array, for every element, check if there is a pair
//             for(int j = 0; j < n2; j++) {
                
//                 // Iterate through the third array, for every element, check if there is an element
//                 for(int k = 0; k < n3; k++) {
                    
//                     int sum = nums1[i] + nums2[j] + nums3[k];
                        
//                     // Find the occurences of -sum in fourth array
//                     count += hash[-1 * sum];
                    
//                 }
//             }
//         }
        
        
        // Sort the array
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        sort(nums3.begin() , nums3.end());
        sort(nums4.begin() , nums4.end());
        
        int n1 = nums1.size() , n2 = nums2.size() , n3 = nums3.size() , n4 = nums4.size() , count = 0;
        unordered_map <int , int> hash;
        
        // Store all the possible sums of elements in third and fourth array
        for(int i = 0; i < n3; i++) {
            for(int j = 0; j < n4; j++) {
                hash[nums3[i] + nums4[j]]++;
            }
        }
        
        // Iterate through the first array, for every element, check if there is a triplet
        for(int i = 0; i < n1; i++) {
            
            // Iterate through the second array, for every element, check if there is a pair
            for(int j = 0; j < n2; j++) {
                    
                int sum = nums1[i] + nums2[j];

                // Find the occurences of -sum in fourth array
                count += hash[-1 * sum];

            }
        }
        
        return count;
    }
};