class RangeFreqQuery {
public:
    int hbs(vector <int> &a , int key) {
        int ans = a.size();
        int low = 0 , high = a.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(a[mid] >= key) {
                if(a[mid] == key) return mid;
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    int lbs(vector <int> &a , int key) {
        int ans = -1;
        int low = 0 , high = a.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(a[mid] <= key) {
                if(a[mid] == key) return mid;
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    map <int , vector <int>> hash;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            hash[arr[i]].push_back(i);
        }
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < hash[arr[i]].size(); j++) cout << hash[arr[i]][j] << " ";
        //     cout << endl;
        // }
    }
    int bs(vector <int> &arr , int key) {
        int low = 0 , high = arr.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == key) return mid;
            if(arr[mid] > key) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
    int query(int left, int right, int value) {
        if(left == right) return (bs(hash[value] , right) != -1) ? 1 : 0;
        int l = hbs(hash[value] , left);
        int r = lbs(hash[value] , right);
        // cout << l << "  " << r << endl;
        return (r - l + 1) ;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */