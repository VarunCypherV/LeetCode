//removed unncessary conversions runtime 7ms
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> hashmap1;
        for (char ch : s) {
            hashmap1[ch]++;
        }
        for (char ch : t) {
            if (hashmap1[ch] == 0) {
                return false;
            }
            hashmap1[ch]--;
        }
        for (auto x : hashmap1) {
            if (x.second != 0) {
                return false;
            }
        }
        return true;
    }
};
