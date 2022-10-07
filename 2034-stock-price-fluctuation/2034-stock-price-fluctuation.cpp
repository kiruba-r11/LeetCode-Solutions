class StockPrice {
public:
    set <pair <int , int>> s;
    map <int , int> hash;
    pair <int , int> cur;
    StockPrice() {
        cur.first = 0;
        cur.second = 0;
    }
    
    void update(int timestamp, int price) {
        if(timestamp >= cur.second) {
            cur.first = price;
            cur.second = timestamp;
        }
        
        if(hash.find(timestamp) != hash.end()) s.erase({hash[timestamp] , timestamp});
        
        s.insert({price , timestamp});
        hash[timestamp] = price;
    }
    
    int current() {
        return cur.first;
    }
    
    int maximum() {
        return s.rbegin()->first;
    }
    
    int minimum() {
        return s.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */