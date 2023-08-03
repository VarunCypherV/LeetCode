class Solution {
public:
    static bool count_sort(const pair<int, int>& a, const       pair<int, int>& b) {
        return a.second < b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> hmap;
         for(int i : nums){
                hmap[i]++;  
        }
        vector<pair<int, int>> freq_pairs;
        for (const auto& x : hmap) {
            freq_pairs.emplace_back(x);
        }
              
        sort(freq_pairs.begin(), freq_pairs.end(), count_sort);
        vector<int> result;
        for (int i =freq_pairs.size()-1; k>0 && i>=0 ; i--,k--) {
            result.push_back(freq_pairs[i].first);
        }
        return result;
    }
};
