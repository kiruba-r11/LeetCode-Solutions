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
        
//         TLE, I really dont know WHY? 
        
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
        
//         /*
        
//         O(N^3) time and O(N) space
//         Idea -> For every triplet, find the count of the element in fourth array which gives the total sum of tuple as 0
        
//         TLE, I really dont know WHY? 
        
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
        

//         /*
        
//         O(N^3) time and O(1) space
//         Idea -> For every doublet, find a pair using two sum technique such that the tuple sum is 0
        
//         TLE, I really dont know WHY? 
        
//         */
        
//         // Sort the array
//         sort(nums1.begin() , nums1.end());
//         sort(nums2.begin() , nums2.end());
//         sort(nums3.begin() , nums3.end());
//         sort(nums4.begin() , nums4.end());
        
//         int n1 = nums1.size() , n2 = nums2.size() , n3 = nums3.size() , n4 = nums4.size() , count = 0;
        
//         // Iterate through the first array, for every element, check if there is a triplet
//         for(int i = 0; i < n1; i++) {
            
//             int temp_i = i + 1;
            
//             // Skipping consecutive elements
//             while(temp_i < n1 && nums1[temp_i] == nums1[i]) temp_i++;
            
//             int temp_i_count = 0;
            
//             // Iterate through the second array, for every element, check if there is a pair
//             for(int j = 0; j < n2; j++) {

//                 int temp_j = j + 1;
                
//                 // Skipping consecutive elements
//                 while(temp_j < n2 && nums2[temp_j] == nums2[j]) temp_j++;
                
//                 int sum = nums1[i] + nums2[j];
//                 int low = 0 , high = n4 - 1;
                
//                 int temp_j_count = 0;
                
//                 // Just a two sum technique
//                 while(low < n3 && high >= 0) {
//                     int cursum = nums3[low] + nums4[high];
                    
//                     if(sum + cursum == 0) {
                        
//                         int temp_low = low + 1;
//                         int temp_high = high - 1;
                        
//                         // Skipping consecutive elements
//                         while(temp_low < n3 && nums3[temp_low] == nums3[low]) temp_low++;
                        
//                         // Skipping consecutive elements
//                         while(temp_high >= 0 && nums4[temp_high] == nums4[high]) temp_high--;
                        
//                         temp_j_count += abs(temp_low - low) * abs(high - temp_high);
                        
//                         low = temp_low;
//                         high = temp_high;
                        
//                     } else if(sum + cursum > 0) {
                        
//                         int temp_high = high - 1;
                        
//                         // Skipping consecutive elements
//                         while(temp_high >= 0 && nums4[temp_high] == nums4[high]) temp_high--;
                        
//                         high = temp_high;
//                     } else {
//                         int temp_low = low + 1;
                        
//                         // Skipping consecutive elements
//                         while(temp_low < n3 && nums3[temp_low] == nums3[low]) temp_low++;
                        
//                         low = temp_low;
//                     }
//                 }

//                 temp_i_count += temp_j_count * abs(temp_j - j);
//                 j = temp_j - 1;
//             }
            
//             count += temp_i_count * abs(temp_i - i);
//             i = temp_i - 1;
//         }
       
        
//         /*
        
//         O(N^2) time and O(N) space
//         Idea -> For every doublet, find the count of the element for every possible sum in third and fourth array which gives the total sum of tuple as 0
        
//         TC passed FINALLY!
        
//         */
        
        
//         // Sort the array
//         sort(nums1.begin() , nums1.end());
//         sort(nums2.begin() , nums2.end());
//         sort(nums3.begin() , nums3.end());
//         sort(nums4.begin() , nums4.end());
        
//         int n1 = nums1.size() , n2 = nums2.size() , n3 = nums3.size() , n4 = nums4.size() , count = 0;
//         unordered_map <int , int> hash;
        
//         // Store all the possible sums of elements in third and fourth array
//         for(int i = 0; i < n3; i++) {
//             for(int j = 0; j < n4; j++) {
//                 hash[nums3[i] + nums4[j]]++;
//             }
//         }
        
//         // Iterate through the first array, for every element, check if there is a triplet
//         for(int i = 0; i < n1; i++) {
            
//             // Iterate through the second array, for every element, check if there is a pair
//             for(int j = 0; j < n2; j++) {
                    
//                 int sum = nums1[i] + nums2[j];

//                 // Find the occurences of -sum in fourth array
//                 count += hash[-1 * sum];

//             }
//         }
        
//         /*
        
//         O(N) time and O(N) space
//         Idea -> For pair sum in first and second array, find the count of pair sum in third and fourth array which gives the total sum of tuple as 0
        
//         TC passed FINALLY! The MOST OPTIMAL SOLUTION POSSIBLE!
        
//         */ 
        
        // Sort the array
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        sort(nums3.begin() , nums3.end());
        sort(nums4.begin() , nums4.end());
        
        int n1 = nums1.size() , n2 = nums2.size() , n3 = nums3.size() , n4 = nums4.size() , count = 0;
        unordered_map <int , int> hash1 , hash2;
        
         // Store all the possible sums of elements in first and second array
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                hash1[nums1[i] + nums2[j]]++;
            }
        }
        
        // Store all the possible sums of elements in third and fourth array
        for(int i = 0; i < n3; i++) {
            for(int j = 0; j < n4; j++) {
                hash2[nums3[i] + nums4[j]]++;
            }
        }
        
        // Iterate through the first hash, for every pair sum of first and second array elements, check if there is a pair sum of third and fourth array elements such that the tuple sum is 0
        for(auto it: hash1) {
            
            count += hash1[it.first] * hash2[-1 * it.first];
        }
         
        return count;
    }
};