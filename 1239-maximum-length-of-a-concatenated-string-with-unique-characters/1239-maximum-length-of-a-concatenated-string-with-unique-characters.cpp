class Solution {
public:
    int ans = 0;
    void length(vector <string> &arr , int i , unordered_map <char , int> &hash , vector <bool> &duplicate) {
        
        if(i == arr.size()) {
            ans = max(ans , (int)hash.size());
            return;
        }
        
        // exclude
        length(arr , i + 1 , hash , duplicate);
        
        // make effort
        bool dup = false;
        for(auto ch: arr[i]) {
            if(hash.find(ch) != hash.end()) {
                dup = true;
                break;
            }
        }
        
        if(dup == false && duplicate[i] == false) {
            cout << arr[i] << endl;
            for(auto ch: arr[i]) hash[ch]++;
        
            // include
            length(arr , i + 1 , hash , duplicate);
        
            // undo effort
            for(auto ch: arr[i]) hash.erase(ch);
        }
    }
    
    int maxLength(vector<string>& arr) {
        unordered_map <char , int> hash;
        vector <bool> duplicate(arr.size() , false);
        vector <int> freq(26 , 0);
        for(int i = 0; i < arr.size(); i++) {
            for(auto ch: arr[i]) {
                if(freq[ch - 'a'] != 0) {
                    duplicate[i] = true;
                    break;
                }
                freq[ch - 'a']++;
            }
            freq.clear();
            freq.resize(26);
        }
        
        length(arr , 0 , hash , duplicate);
        return ans;
    }
};