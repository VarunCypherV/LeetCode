class TimeMap {
private:
    unordered_map<int, vector<pair<string,string>>> storage;
public:
    TimeMap() {
        
    }
    string BinarySearch(vector<pair<string,string>>& nums, string target , int l , int r){
    
        int m = l + (r-l)/2;
        if(l>r){
            return "";
        }
        if(nums[m].first==target){
            return nums[m].second;
        }
        else if(nums[m].first>target){
            return BinarySearch(nums,target,l,m-1);
        }
        else{
            return BinarySearch(nums,target,m+1,r);
        }
        return ""; //if not found
        
    }
    void set(string key, string value, int timestamp) {
        storage[timestamp].push_back({key, value});
        sort(storage[timestamp].begin(), storage[timestamp].end());
}
    
    string get(string key, int timestamp) {
        return BinarySearch(storage[timestamp],key,0,storage[timestamp].size()-1);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
