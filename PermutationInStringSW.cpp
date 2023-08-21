class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
        return false;
    }
    vector<int> charCount(26, 0);
    for (char c : s1) {
        charCount[c - 'a']++;  //so if say letter b means 'b'-'a' = 1 so index = 1 has this value updated
    }
    vector<int> window(26, 0);
    for (int i = 0; i < s1.size(); i++) {
        window[s2[i] - 'a']++; //update value for all the letter in s2
    } // initializing window with first s1 size() characters of s2
    // sliding the window through s2
    for (int i = 0; i < s2.size() - s1.size(); i++) {
        if (window == charCount) {
            return true;
        }
        // Update the sliding window
        window[s2[i] - 'a']--;  //removing left most element
        window[s2[i + s1.size()] - 'a']++; //adding right most element
    }
    return window == charCount; // Check the last window
}

};
