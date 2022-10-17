class Solution {
public:
    bool checkIfPangram(string sen) {
        vector <int> hash(26 , 0);
        for(auto i: sen) 
            hash[i - 97]++;
        for(auto i: hash)
            if(i == 0) return false;
        return true;
    }
};