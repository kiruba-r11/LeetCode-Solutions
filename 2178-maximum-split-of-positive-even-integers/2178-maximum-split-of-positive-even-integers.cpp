class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector <long long> ans;
        
        if(finalSum & 1) return ans;
        
        long long num = 2 , curSum = 0;
        while(finalSum > 0) {
            ans.push_back(num);
            finalSum -= num;
            curSum += num;
            num += 2;
        }
        
        if(finalSum == 0) return ans;
        curSum -= ans.back();
        finalSum += ans.back();
        ans.pop_back();
        ans[ans.size() - 1] += finalSum;
        return ans;
    }
};


    