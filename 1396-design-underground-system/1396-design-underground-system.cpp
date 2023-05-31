class UndergroundSystem {
public:
    map <int , pair <string , int>> cust;
    map <pair <string , string> , pair <double , int>> time;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cust[id] = {stationName , t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair <string , int> customer = cust[id];
        pair <double , int> times = time[{customer.first , stationName}];
        
        times.first = ((double)(times.first * (double)times.second + (t - customer.second))) / (times.second + 1);
        times.second += 1;
        time[{customer.first , stationName}] = times;
        cust[id] = {};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return time[{startStation , endStation}].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */