class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        map <int , int> hash;
        priority_queue <pair <int , int>> pq;
        int k = k1 + k2 , n = nums1.size();
        
        for(int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            hash[diff]++;
        }
        
        for(auto i: hash) pq.push({i.first , i.second});
        
        while(k > 0 && pq.size()) {
            int diff = pq.top().first;
            int cnt = pq.top().second;
            pq.pop();
            
            if(k >= cnt) {
                k -= cnt;
                diff--;
                
                if(diff > 0) {
                    if(pq.size() && pq.top().first == diff) {
                        cnt += pq.top().second;
                        pq.pop();
                        
                        pq.push({diff , cnt});
                    } else {
                        pq.push({diff , cnt});
                    }
                }
            } else {
                int rem = k;
                cnt -= rem;
                
                int newdiff = diff;
                newdiff--;
                
                if(newdiff > 0) {
                    if(pq.size() && pq.top().first == newdiff) {
                        rem += pq.top().second;
                        pq.pop();
                        
                        pq.push({newdiff , rem});
                    } else {
                        pq.push({newdiff , rem});
                    }
                }
                pq.push({diff , cnt});
                k = 0;   
            }
        }
        
        long long ans = 0;
        
        while(pq.size()) {
            int diff = pq.top().first;
            int cnt = pq.top().second;
            pq.pop();

            while(cnt--) ans += diff * 1L * diff;
        }
        
        return ans;
    }
};