class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map; // Changed the variable name
        vector<int> result;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]] = i; //position of last Occurence of the variable
        }
        
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.length(); i++) {
            end = max(end, map[s[i]]); // end = last occurence of variable
            if (i == end) { //if we r at last occurence push the size of that
                result.push_back(end - start + 1);
                start = end + 1; //and move start to next element
            }
        }
        
        return result;
    }
};
