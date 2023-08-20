//concept correct
class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> storage;
public:
    TimeMap() {
        
    }
    string BinarySearch(vector<pair<int, string>>& nums, int target, int l, int r) {
    if (l > r) {
        if (r >= 0) {
            return nums[r].second;  // if value at all there return if no match :)
        }
        return "";
    }
    int m = l + (r - l) / 2;
    if (nums[m].first == target) {
        return nums[m].second;
    } else if (nums[m].first > target) {
        return BinarySearch(nums, target, l, m - 1);
    } else {
        return BinarySearch(nums, target, m + 1, r);
    }
}

    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp, value});
        sort(storage[key].begin(), storage[key].end());
}
    
    string get(string key, int timestamp) {
        return BinarySearch(storage[key],timestamp,0,storage[key].size()-1);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
