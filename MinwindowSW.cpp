class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for (char c : t) {
            map[c]++;
        }

        int counter = t.size(), left = 0, right = 0, min = INT_MAX, head = 0;
        while (right < s.size()){
            if (map[s[right++]]-- > 0) {
                counter--;
            }
            while (counter == 0) {
                if (right - left < min) {
                    head = left;
                    min = right - head;
                }
                if (map[s[left++]]++ == 0) { //if next left was -1 , then inc to minimize window
                    counter++;
                }
            }  
        }
        return min == INT_MAX ? "" : s.substr(head, min);
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq, windowFreq;
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        int requiredChars = t.size();
        // Count the frequency of characters in string t
        for (char c : t) {
            tFreq[c]++;
        }
        while (right < s.size()) {
            char currentChar = s[right];
            
            if (tFreq.find(currentChar) != tFreq.end()) {
                windowFreq[currentChar]++;
                if (windowFreq[currentChar] <= tFreq[currentChar]) { //less than eq uz if 2 bs then
                // 1 < 2 so yea req char --
                    requiredChars--;
                }
                while (requiredChars == 0) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        minStart = left;
                    }
                    //check if left there cuz already counted by right
                    if (tFreq.find(s[left]) != tFreq.end()) {
                        windowFreq[s[left]]--;
                        if (windowFreq[s[left]] < tFreq[s[left]]) {
                            requiredChars++;
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        
        if (minLen == INT_MAX) {
            return "";
        }
        
        return s.substr(minStart, minLen);
    }
};
