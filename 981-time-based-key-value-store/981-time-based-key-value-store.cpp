class TimeMap {
public:
    map <string , vector <pair <int , string>>> hash;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        int n = hash[key].size();
        
        int low = 0 , high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(hash[key][mid].first == timestamp) return hash[key][mid].second;
            else if(hash[key][mid].first > timestamp) high = mid - 1;
            else low = mid + 1;
        }
        
        if(high < 0) return "";
        return hash[key][high].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */