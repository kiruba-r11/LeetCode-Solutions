class TimeMap {
public:
    map <pair <string , int> , string> hash;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[{key , timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        
        int ans = -1 , high = timestamp;
        while(high > 0) {
            if(hash.find({key , high}) != hash.end()) {
                ans = high;
                break;
            }
            high--;
        }
        
        if(ans == -1) return "";
        return hash[{key , ans}];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */