class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum & 1) return {};
        long long start = 2;
        
        vector <long long> ans;
        while(finalSum >= start) {
            ans.push_back(start);
            finalSum -= start;
            start += 2;
        }
        
        if(finalSum != 0) {
            long long last = ans.back();
            ans.pop_back();
            last += finalSum;
            ans.push_back(last);
        }
        
        return ans;
    }
};