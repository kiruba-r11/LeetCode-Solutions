class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        /*
        
        O(N) time and space complexity
        Idea -> Hashing
        
        */
        
        int n = s.size();
        vector <int> hash(26 , 0);
        
        for(int i = 0; i < n; i++) {
            hash[s[i] - 97]++;
        }
        
        vector <int> ans;
        unordered_map <char , bool> found;
        int j = 0;
        
        while(j < n) {
            int unique = 0;
            int start = j;
            int i = j;
            while(i < n) {
                if(hash[s[i] - 97] >= 1) {
                    hash[s[i] - 97]--;
                    if(hash[s[i] - 97] == 0) unique++;
                }
                found[s[i]] = true;
                int elem = i - start + 1;
                i++;
                if(unique == found.size()) {
                    ans.push_back(elem);
                    break;
                }
            }
            found.clear();
            j = i;
        }
        
        return ans;
    }
};